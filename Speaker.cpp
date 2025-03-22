#include "Speaker.h"
#include <SoftwareSerial.h> 
#include "DFRobotDFPlayerMini.h"

Speaker::Speaker(uint8_t rxPin, uint8_t txPin) : mySoftwareSerial(rxPin, txPin) {

}

void Speaker::play() {
    delay(5000);
    mySoftwareSerial.begin(9600);  
    Serial.begin(9600);

    Serial.println();
    Serial.println("DFRobot DFPlayer Mini Demo");
    Serial.println("Initializing DFPlayer ... (May take 3~5 seconds)");

    if (!myDFPlayer.begin(mySoftwareSerial)) {
        Serial.println("Unable to begin:");
        Serial.println("1. Please recheck the connection!");
        Serial.println("2. Please insert the SD card!");
        while (true);
    }
    Serial.println("DFPlayer Mini online.");

    myDFPlayer.setTimeOut(500);
    myDFPlayer.volume(20);

  
    myDFPlayer.play(1);
    delay(2000);
    myDFPlayer.pause();
    Serial.println("Stop play");
    delay(2000);
    myDFPlayer.loop(1);
    delay(1000);
}
