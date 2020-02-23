#include "PinConfiguration.h"
#include "Constants.h"

class StepperMotorControl {

  private:

    boolean Dir;
    byte DirPin;
    byte StepperPin;
    long int Steps;

  public:

    void step(boolean dir, byte dirPin, byte stepperPin, long int steps){

      Dir = dir;
      DirPin = dirPin;
      StepperPin = stepperPin;
      Steps = steps;
      
      digitalWrite(dirPin, dir);
      
      for (long int i = 0; i < steps; i++) {
        digitalWrite(stepperPin, HIGH);
        delayMicroseconds(delayTime);
        digitalWrite(stepperPin, LOW);
        delayMicroseconds(delayTime);
      }

      if (dir) {
        if (dirPin == X_DIR) {
          X_VAL = X_VAL + 1;
        } else if (dirPin == Y_DIR) {
          Y_VAL = Y_VAL + 1;
        } else if (dirPin == Z_DIR) {
          Z_VAL = Z_VAL + 1;
        }
      } else {
        if (dirPin == X_DIR) {
          X_VAL = X_VAL - 1;
        } else if (dirPin == Y_DIR) {
          Y_VAL = Y_VAL - 1;
        } else if (dirPin == Z_DIR) {
          Z_VAL = Z_VAL - 1;
        }
      }
      
      Serial.println((String)"X : " + X_VAL + (String)" CM , Y : " + Y_VAL +  (String)" CM , Z : " + Z_VAL + (String)" CM");
      
    }
};

StepperMotorControl SMC;
