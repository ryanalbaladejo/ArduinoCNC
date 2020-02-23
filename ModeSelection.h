#include "PlantCoordinates.h"

class ModeSelection {

  private:

  public:

    int modeSelected;

    void check() {
      
      if (calibrate = 1){//digitalRead(modePin1) == 0 && digitalRead(modePin0) == 0) {
        modeSelected = 1;
        Serial.println("MODE 1 SELECTED.");
      } else if (digitalRead(modePin1) == 0 && digitalRead(modePin0) == 0) {
        modeSelected = 2;
        Serial.println("MODE 2 SELECTED.");
      } else if (digitalRead(modePin1) == 0 && digitalRead(modePin0) == 0) {
        modeSelected = 3;
        Serial.println("MODE 3 SELECTED.");
      } else if (digitalRead(modePin1) == 0 && digitalRead(modePin0) == 0) {
        modeSelected = 4;
        Serial.println("MODE 4 SELECTED.");
      } else {
        Serial.println("INVALID MODE SELECTION.");
      }
      
    }

    void assign() {

      switch(modeSelected){
        default:
          Serial.println("INVALID!");
          break;
         case 1:
          xDistance = 15;
          xStart = 31;
          yStart = 15;
          //Serial.println("Here");
          //Serial.println(xStart);
          
      }
        
    }

};

ModeSelection mode;
