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
  void toggle(int ms_delay) 
  {
    turn_on();
    delay(ms_delay);
    turn_off();
  }
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
  ~UltraSound() {}

  void toggle() { active = !active; }
  void set_active(bool state) { active = state; }
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
  float tmp;
  void run()
  {
    play_sound();
    float distance = get_distance();
    if (distance <= max_distance && distance > 0.0)
      active = true;
    else
      active = false;
  }
  bool get_active() { return active; }
};

class RollRamp {
private:
  LED* leds[2];
  UltraSound* sensors[2];
  int i_start_sensor;
  unsigned long start_time;
  unsigned long end_time;
  bool measuring;
  float speed;
  const int RED_LED = 12;
  const int GREEN_LED = 13;
  const int I_LED_RED = 0;
  const int I_LED_GREEN = 1;
  
public:
  RollRamp() {}
  RollRamp(float cm_max_distance)
  {
    exeSetup();
    i_start_sensor = 1;
    measuring = false;
    sensors[0] = new UltraSound(9, 8, cm_max_distance);
    sensors[1] = new UltraSound(12, 10, cm_max_distance);
    leds[I_LED_RED] = new LED(RED_LED);
    leds[I_LED_GREEN] = new LED(GREEN_LED);
  }
  //~RollRamp() { delete[] sensors; }

  int get_active_sensor() 
  {
    for (int i = 0; i < 2; ++i)
    {
      if (sensors[i]->get_active())
        return i;
    }
    
    return -1;
  }
  void run() 
  {    
    if (!measuring)
    {
      sensors[1]->run();
      int i_cur_active_sensor = get_active_sensor();
      leds[I_LED_GREEN]->turn_on();
      if (i_cur_active_sensor == i_start_sensor)
      {
        leds[I_LED_GREEN]->turn_off();
        measuring = true;
        start_time = millis();
      }
    }
    else 
    {
      sensors[0]->run();
      int i_cur_active_sensor = get_active_sensor();
      if (i_cur_active_sensor != -1 && i_cur_active_sensor != i_start_sensor)
      {
        end_time = millis();
        measuring = false;
        unsigned long ellapsed = (end_time - start_time) / 1000;
        Serial.print(ellapsed);
        Serial.print(",");
        float speed = 19 / ellapsed;
        Serial.println(speed);
        leds[I_LED_RED]->turn_on();
        writeNum(ellapsed, (3000 * 5));
        clearDisplay(1);
        leds[I_LED_RED]->turn_off();
        sensors[0]->set_active(false);
        sensors[1]->set_active(false);
      }
    }
  }
};

float cm_max_distance = 5.0;
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
