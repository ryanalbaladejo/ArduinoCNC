#include "PlantCoordinates.h"

class ModeSelection {

  private:

  public:

    int modeSelected;

    void check() {
      
      // NOTE: CHANGE ARGUMENT AND MODESELECTED VALUE IF TESTING (See ArduinoCNC_MAIN for instructions.)
      
      if (digitalRead(modePin1) == 0 && digitalRead(modePin0) == 0) {   
        modeSelected = 1;
        Serial.println("MODE 1 SELECTED.");
      } else if (digitalRead(modePin1) == 0 && digitalRead(modePin0) == 1) {
        modeSelected = 2;
        Serial.println("MODE 2 SELECTED.");
      } else if (digitalRead(modePin1) == 1 && digitalRead(modePin0) == 0) {
        modeSelected = 3;
        Serial.println("MODE 3 SELECTED.");
      } else if (digitalRead(modePin1) == 1 && digitalRead(modePin0) == 1) {
        modeSelected = 4;
        Serial.println("MODE 4 SELECTED.");
      } else {
        Serial.println("INVALID MODE SELECTION.");
      }

    }

    void assign() {

      switch (modeSelected) {
        default:
          Serial.println("INVALID!");
          break;
        case 1:
          xSpace    = MODE00_xSpace;
          xStart    = MODE00_xStart;
          ySpace    = MODE00_ySpace;
          ySeed     = MODE00_ySeed;
          yWater    = MODE00_yWater;
          noOfCols  = MODE00_noOfCols;
          noOfRows  = MODE00_noOfRows;
          break;
        case 2:
          xSpace    = MODE01_xSpace;
          xStart    = MODE01_xStart;
          ySpace    = MODE01_ySpace;
          ySeed     = MODE01_ySeed;
          yWater    = MODE01_yWater;
          noOfCols  = MODE01_noOfCols;
          noOfRows  = MODE01_noOfRows;
          break;
        case 3:
          xSpace    = MODE10_xSpace;
          xStart    = MODE10_xStart;
          ySpace    = MODE10_ySpace;
          ySeed     = MODE10_ySeed;
          yWater    = MODE10_yWater;
          noOfCols  = MODE10_noOfCols;
          noOfRows  = MODE10_noOfRows;
          break;
        case 4:
          xSpace    = MODE11_xSpace;
          xStart    = MODE11_xStart;
          ySpace    = MODE11_ySpace;
          ySeed     = MODE11_ySeed;
          yWater    = MODE11_yWater;
          noOfCols  = MODE11_noOfCols;
          noOfRows  = MODE11_noOfRows;
          break;
      }

    }

};

ModeSelection mode;
