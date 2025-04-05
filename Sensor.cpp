#include "Sensor.h"


Sensor::Sensor(int pin_echo, int pin_trig)
  : sonar(pin_echo, pin_trig, MAX_DISTANCE) {  
  PIN_ECHO = pin_echo;
  PIN_TRIG = pin_trig;
}
int Sensor::get_value() {
  return sonar.ping_cm(); 
}
