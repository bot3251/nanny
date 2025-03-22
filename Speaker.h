#ifndef SPEAKER_H
#define SPEAKER_H

#include <SoftwareSerial.h>
#include "DFRobotDFPlayerMini.h"

class Speaker {
public:
  Speaker(uint8_t rxPin, uint8_t txPin); 
  void play();

private:
  SoftwareSerial mySoftwareSerial;  
  DFRobotDFPlayerMini myDFPlayer;
};

#endif
