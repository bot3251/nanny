#include "FaceRobot.h"

int pinCS = 9;
int numberOfHorizontalDisplays = 1;
int numberOfverticalDisplays = 4;
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfverticalDisplays);
unsigned long tmr1 = 0;
unsigned long tmr2 = 0;
bool is_open = false;

void FaceRobot::start() {
  delay(5000);
  matrix.setIntensity(1);
}

void FaceRobot::start_smile() {
  // smile();
  // matrix.write();
  if (millis() - tmr1 >= 5000 && is_open==0) {  // ищем разницу
    tmr2=millis();
    is_open=1;
    none_smile();
    matrix.write();
  }
  if (millis() - tmr2 > 300 && is_open==1){
    is_open=0;
    tmr1=millis();
    smile();
    matrix.write();
  }

  // delay(5000);
  // delay(300);
  //  matrix.drawPixel(5, 10, HIGH);
  //     matrix.write();
  //     delay(300);
}

void FaceRobot::smile() {
    matrix.drawPixel(7, 24, HIGH);  //
    matrix.drawPixel(7, 23, HIGH);  //
    matrix.drawPixel(7, 25, HIGH);  //
    matrix.drawPixel(7, 22, HIGH);  //
    matrix.drawPixel(7, 7, HIGH);   //
    matrix.drawPixel(7, 8, HIGH);   //
    matrix.drawPixel(7, 6, HIGH);   //
    matrix.drawPixel(7, 9, HIGH);   //
    matrix.drawPixel(3, 7, HIGH);   //
    matrix.drawPixel(4, 7, HIGH);   //
    matrix.drawPixel(6, 26, HIGH);  //
    matrix.drawPixel(6, 21, HIGH);  //
    matrix.drawPixel(6, 5, HIGH);   //
    matrix.drawPixel(5, 27, HIGH);  //
    matrix.drawPixel(5, 20, HIGH);  //
    matrix.drawPixel(5, 4, HIGH);   //
    matrix.drawPixel(4, 27, HIGH);  //
    matrix.drawPixel(4, 4, HIGH);   //
    matrix.drawPixel(4, 20, HIGH);  //
    matrix.drawPixel(4, 23, HIGH);  //
    matrix.drawPixel(4, 24, HIGH);  //
    matrix.drawPixel(3, 20, HIGH);
    matrix.drawPixel(3, 23, HIGH);
    matrix.drawPixel(3, 24, HIGH);
    matrix.drawPixel(3, 27, HIGH);
    matrix.drawPixel(3, 4, HIGH);
    matrix.drawPixel(3, 5, LOW);   //
    matrix.drawPixel(3, 6, LOW);   //
    matrix.drawPixel(3, 8, HIGH);  //
    matrix.drawPixel(3, 9, LOW);   //
    matrix.drawPixel(3, 10, LOW);  //
    matrix.drawPixel(3, 21, LOW);  //
    matrix.drawPixel(3, 22, LOW);  //
    matrix.drawPixel(3, 23, LOW);  //
    matrix.drawPixel(3, 24, LOW);  //
    matrix.drawPixel(3, 25, LOW);  //
    matrix.drawPixel(3, 26, LOW);
    matrix.drawPixel(4, 8, HIGH);  //
    matrix.drawPixel(2, 27, HIGH);
    matrix.drawPixel(2, 20, HIGH);
    matrix.drawPixel(2, 4, HIGH);
    matrix.drawPixel(1, 26, HIGH);
    matrix.drawPixel(1, 21, HIGH);
    matrix.drawPixel(1, 5, HIGH);
    matrix.drawPixel(1, 10, HIGH);
    matrix.drawPixel(2, 11, HIGH);
    matrix.drawPixel(3, 11, HIGH);
    matrix.drawPixel(4, 11, HIGH);
    matrix.drawPixel(5, 11, HIGH);
    matrix.drawPixel(6, 10, HIGH);
    matrix.drawPixel(0, 24, HIGH);
    matrix.drawPixel(0, 23, HIGH);
    matrix.drawPixel(0, 25, HIGH);
    matrix.drawPixel(0, 22, HIGH);
    matrix.drawPixel(0, 7, HIGH);
    matrix.drawPixel(0, 8, HIGH);
    matrix.drawPixel(0, 6, HIGH);
    matrix.drawPixel(0, 9, HIGH);
    matrix.drawPixel(3, 23, HIGH);  //
    matrix.drawPixel(3, 24, HIGH);
}

void FaceRobot::none_smile() {
    matrix.drawPixel(7, 24, LOW);   //
    matrix.drawPixel(7, 23, LOW);   //
    matrix.drawPixel(7, 25, LOW);   //
    matrix.drawPixel(7, 22, LOW);   //
    matrix.drawPixel(7, 7, LOW);    //
    matrix.drawPixel(7, 8, LOW);    //
    matrix.drawPixel(7, 6, LOW);    //
    matrix.drawPixel(7, 9, LOW);    //
    matrix.drawPixel(6, 5, LOW);    //
    matrix.drawPixel(6, 26, LOW);   //
    matrix.drawPixel(6, 21, LOW);   //
    matrix.drawPixel(5, 4, LOW);    //
    matrix.drawPixel(5, 27, LOW);   //
    matrix.drawPixel(5, 20, LOW);   //
    matrix.drawPixel(4, 4, LOW);    //
    matrix.drawPixel(4, 24, LOW);   //
    matrix.drawPixel(4, 23, LOW);   //
    matrix.drawPixel(4, 20, LOW);   //
    matrix.drawPixel(4, 27, LOW);
    matrix.drawPixel(4, 8, LOW);   //
    matrix.drawPixel(3, 5, HIGH);   //
    matrix.drawPixel(3, 6, HIGH);   //
    matrix.drawPixel(4, 7, LOW);   //
    matrix.drawPixel(3, 9, HIGH);   //
    matrix.drawPixel(3, 10, HIGH);  //
    matrix.drawPixel(3, 21, HIGH);  //
    matrix.drawPixel(3, 22, HIGH);  //
    matrix.drawPixel(3, 25, HIGH);  //
    matrix.drawPixel(3, 26, HIGH);  //
    matrix.drawPixel(4, 11, LOW);
    matrix.drawPixel(5, 11, LOW);
    matrix.drawPixel(6, 10, LOW);
}
