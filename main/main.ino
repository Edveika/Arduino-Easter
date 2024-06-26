#include "Display_Controller_New.h"

class LED {
private:
  int led_pin;

public:
  LED(const int pin) 
  {
    led_pin = pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  void turn_on() { digitalWrite(led_pin, HIGH); }
  void turn_off() { digitalWrite(led_pin, LOW); }
};

class UltraSound {
private:
  int trig_pin;  
  int echo_pin; 
  bool active;
  float max_distance;

public:
  UltraSound() {}
  UltraSound(int trig_pin, int echo_pin, float max_distance)
  {
    pinMode(trig_pin, OUTPUT);  
    pinMode(echo_pin, INPUT);  
    this->trig_pin = trig_pin;
    this->echo_pin = echo_pin;
    this->max_distance = max_distance;
    active = false;
  }

  void set_active(bool state) { active = state; }
  bool get_active() { return active; }
  void play_sound() 
  {
    digitalWrite(trig_pin, LOW);  
    delayMicroseconds(2);  
    digitalWrite(trig_pin, HIGH);  
    delayMicroseconds(10);  
    digitalWrite(trig_pin, LOW); 
  }
  float get_distance()
  {
    float duration = pulseIn(echo_pin, HIGH);  
    return (duration * 0.0343) / 2; 
  }
  void run()
  {
    play_sound();
    float distance = get_distance();
    active = (distance <= max_distance && distance > 0.0);
  }
};

class RollRamp {
private:
  LED* leds[2];
  UltraSound* sensors[2];
  int i_start_sensor;
  unsigned long start_time;
  unsigned long end_time;
  bool rolling_started;
  const int RED_LED = 12;
  const int GREEN_LED = 13;
  const int I_LED_RED = 0;
  const int I_LED_GREEN = 1;
  const float CM_RAMP_LENGTH = 76.5f;
  
public:
  RollRamp() {}
  RollRamp(float cm_max_distance)
  {
    exeSetup();
    i_start_sensor = 1;
    rolling_started = false;
    sensors[0] = new UltraSound(9, 8, cm_max_distance);
    sensors[1] = new UltraSound(12, 10, cm_max_distance);
    leds[I_LED_RED] = new LED(RED_LED);
    leds[I_LED_GREEN] = new LED(GREEN_LED);
  }
  ~RollRamp()
  { 
    delete[] sensors;
    delete[] leds;
  }

  int get_active_sensor() 
  {
    for (int i = 0; i < sizeof(sensors) / sizeof(sensors[0]); ++i)
    {
      if (sensors[i]->get_active())
        return i;
    }
    
    return -1;
  }
  void run() 
  {    
    if (!rolling_started)
    {
      sensors[1]->run();
      leds[I_LED_GREEN]->turn_on();
      if (get_active_sensor() == i_start_sensor)
      {
        leds[I_LED_GREEN]->turn_off();
        rolling_started = true;
        start_time = millis();
      }
    }
    else 
    {
      sensors[0]->run();
      if (get_active_sensor() != (-1 || i_start_sensor))
      {
        end_time = millis();
        rolling_started = false;
        unsigned long ellapsed = (end_time - start_time);
        Serial.print(ellapsed);
        Serial.print(",");
        float speed = CM_RAMP_LENGTH / (ellapsed / 1000.0f);
        Serial.println(speed);
        leds[I_LED_RED]->turn_on();
        // 3000 - 3000 cycles, same as 1 second. will show number for 5 seconds
        writeNum(ellapsed, (3000 * 5));
        clearDisplay(1);
        leds[I_LED_RED]->turn_off();
        sensors[0]->set_active(false);
        sensors[1]->set_active(false);
      }
    }
  }
};

float cm_max_distance = 10.0;
RollRamp* roll_ramp;

void setup() 
{
  Serial.begin(9600); 
  roll_ramp = new RollRamp(cm_max_distance);
}

void loop() 
{
  roll_ramp->run();
}
