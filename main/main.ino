class UltraSound {
 public:
  int trig_pin;  
  int echo_pin; 
  bool active;
  float max_distance;

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
    float distance = (duration*0.0343) / 2; 

    if (distance <= max_distance)
      active = true;

    return distance;
  }
};

float cm_max_distance = 5.0;
UltraSound* sensors[2];

void setup() 
{
  Serial.begin(9600);
  sensors[0] = new UltraSound(10, 9, cm_max_distance);
}

void loop() 
{
  sensors[0]->play_sound();
  float dst = sensors[0]->get_distance();
  Serial.println(dst);
}
