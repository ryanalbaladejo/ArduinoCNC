#include "StepperMotorControl.h"
#include "Commands.h"

void setup() {
  
  Serial.begin(9600);
  
  pinMode(X_DIR, OUTPUT);
  pinMode(Y_DIR, OUTPUT);
  pinMode(Z_DIR, OUTPUT);
  
  pinMode(X_STP, OUTPUT);
  pinMode(Y_STP, OUTPUT);
  pinMode(Z_STP, OUTPUT);
  
  pinMode(EN, OUTPUT);
  
  pinMode(X_LIM, INPUT_PULLUP);
  pinMode(Y_LIM, INPUT_PULLUP);
  pinMode(Z_LIM, INPUT_PULLUP);
    
  digitalWrite(EN, LOW);
  
}

void loop() {

  if(idle == 0){
   if(calibrate == 1){
      AGE.beginCalbiration();
    } else if(calibrate == 0) {
      Serial.println("-->XYZ ROBOT CALIBRATION SUCCESS.");
      idle = 1;
    }  
  } else if(DONE == 0 && idle == 1){
    Serial.println("Nothing to do.");
    DONE = 1;
  } else if(DONE == 1 && idle == 1){
    
  }
  
}
