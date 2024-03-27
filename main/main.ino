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
    if (distance <= max_distance)
      active = true;
    else
      active = false;
  }
  bool get_active() { return active; }
};

class Measure {
private:
  UltraSound* sensors[2];
  int i_start_sensor;
  unsigned long start_time;
  unsigned long end_time;
  bool measuring;
  
public:
  Measure() {}
  Measure(float cm_max_distance)
  {
    i_start_sensor = 1;
    measuring = false;
    sensors[0] = new UltraSound(10, 9, cm_max_distance);
    sensors[1] = new UltraSound(12, 11, cm_max_distance);
  }
  ~Measure() { delete[] sensors; }

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
    for (int i = 0; i < 2; ++i)
      sensors[i]->run();

    int i_cur_active_sensor = get_active_sensor();
    if (!measuring)
    {
      if (i_cur_active_sensor == i_start_sensor)
      {
        measuring = true;
        start_time = millis();
        Serial.print("Sensor: ");
        Serial.println(i_start_sensor);
      }
    }
    else 
    {
      if (i_cur_active_sensor != -1 && i_cur_active_sensor != i_start_sensor)
      {
        end_time = millis();
        measuring = false;
        unsigned long ellapsed = (end_time - start_time) / 1000;
        Serial.print(ellapsed);
        Serial.println(" seconds");
      }
    }
  }
};

float cm_max_distance = 30.0;
Measure* measure;

void setup() 
{
  Serial.begin(9600);
  measure = new Measure(cm_max_distance);
}

void loop() 
{
  measure->run();
  //sensors[0]->play_sound();
  //float dst = sensors[0]->get_distance();
  //Serial.println(dst);
}
