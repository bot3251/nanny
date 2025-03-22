#include "FaceRobot.h"
#include "Speaker.h"

FaceRobot faceRobot;
Speaker speaker(10, 11);

void setup() {
  faceRobot.start();
  faceRobot.start_smile();
  speaker.play();
}

void loop() {

}
