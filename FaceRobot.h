#ifndef FACEROBOT_H
#define FACEROBOT_H

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

class FaceRobot {
public:
  void start();
  void start_smile();
private:

  void smile();
  void none_smile();
  unsigned long tmr1;
  unsigned long tmr2;
  bool is_open; 
};

#endif
