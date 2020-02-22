#include "StepperMotorControl.h"

#define EN        8

// DIRECTION PINS
#define X_DIR     5
#define Y_DIR     6
#define Z_DIR     7
#define X_STP     2



int delayTime = 1000; //Delay between each pause (uS)
long int stps = 50; // microsteps per revolution with 1/32 microstepping
const int limitPin = 9; //enable limitPin
boolean touched = false;


void setup() {
  Serial.begin(9600);
  pinMode(X_DIR, OUTPUT);
  pinMode(X_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(limitPin, INPUT_PULLUP);
  digitalWrite(EN, LOW);
}

void loop() {
  Serial.println(digitalRead(limitPin));
  if (touched == true && digitalRead(limitPin) == HIGH) {
    //delay(200);
    SMC.step(true, X_DIR, X_STP, stps);
    //touched = false;
  }
  else if (digitalRead(limitPin) == LOW) //clicked
  {
    touched = true;
    Serial.println("touched");
    delay(1000);
  } else if (digitalRead(limitPin) == HIGH) {
    SMC.step(false, X_DIR, X_STP, stps);
    //  Serial.println("elseif");
  } else {
    touched = false;
    //  Serial.println("else");
  }
}
