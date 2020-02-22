#include "StepperMotorControl.h"
#include "Commands.h"

//boolean touched = false;

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

if(calibrate == 1){
  delay(100);
  AGE.beginCalbiration();
} else {
  Serial.println("-->XYZ ROBOT CALIBRATION SUCCESS.");
  delay(10000000);
}

}
