#include "Declarations.h"

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
  
      //int delayTime;
      
      digitalWrite(dirPin, dir);
      
      for (long int i = 0; i < steps; i++) {
        digitalWrite(stepperPin, HIGH);
        delayMicroseconds(delayTime);
        digitalWrite(stepperPin, LOW);
        delayMicroseconds(delayTime);
        //Serial.println(delayTime);
      }
    }

};

StepperMotorControl SMC;
