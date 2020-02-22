#include "StepperMotorControl.h"
#include "Commands.h"
//#include "Declarations.h"

// STEP PINS
//#define X_STP     2
#define Y_STP     3
#define Z_STP     4

// DIRECTION PINS
//#define X_DIR     5
#define Y_DIR     6
#define Z_DIR     7

// ENABLE PIN
#define EN        8

// LIMIT PINS
#define X_LIM     9
#define Y_LIM     10
#define Z_LIM     11

// RPI-ARDUINO COMMUNICATION PINS
#define seedPin0 ;     //FOR SEEDING:    00 - 5 X 2;   10 - 6 X 2
#define seedPin1 ;     //                01 - 4 X 2    11 - 3 X 2
#define waterPin ;     //FOR WATERING:
#define calibPin ;     //FOR CALIBRATION

//int delayTime = 1000;         //Delay between each pause (uS) 
//long int stps = 50;           // microsteps per revolution with 1/32 microstepping    [50 steps = 1 cm travel]

boolean touched = false;

boolean X_POS = false;    // X RIGHT LIMIT SWITCH
boolean X_NEG = false;    // X LEFT LIMIT SWITCH

boolean Y_POS = false;    // Y DOWN LIMIT SWITCH
boolean Y_NEG = false;    // Y UP LIMIT SWITCH

boolean Z_POS = false;
boolean Z_NEG = false;


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

  AGE.beginCalbiration();

      //SMC.step(false, X_DIR, X_STP, stps);

//  Serial.println(digitalRead(limitPin));
//  if (touched == true && digitalRead(limitPin) == HIGH) {
//    //delay(200);
//    SMC.step(true, X_DIR, X_STP, stps);
//    //touched = false;
//  }
//  else if (digitalRead(X_LIM) == LOW) //clicked
//  {
//    touched = true;
//    Serial.println("touched");
//    delay(1000);
//  } else if (digitalRead(X_LIM) == HIGH) {
//    SMC.step(false, X_DIR, X_STP, stps);
//    //  Serial.println("elseif");
//  } else {
//    touched = false;
//    //  Serial.println("else");
//  }
}
