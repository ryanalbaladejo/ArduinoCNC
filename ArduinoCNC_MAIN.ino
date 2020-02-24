#include "StepperMotorControl.h"
#include "ModeSelection.h"
#include "Commands.h"


void setup() {

  Serial.begin(9600);

  pinMode(X_DIR, OUTPUT);
  pinMode(Y_DIR, OUTPUT);
  pinMode(Z_DIR, OUTPUT);

  pinMode(X_STP, OUTPUT);
  pinMode(Y_STP, OUTPUT);
  pinMode(Z_STP, OUTPUT);

  pinMode(seedPin, INPUT);
  pinMode(waterPin, INPUT);
  pinMode(calibPin, INPUT);

  pinMode(waterPump, OUTPUT);

  pinMode(EN, OUTPUT);

  pinMode(X_LIM, INPUT_PULLUP);
  pinMode(Y_LIM, INPUT_PULLUP);
  pinMode(Z_LIM, INPUT_PULLUP);

  digitalWrite(EN, LOW);
  digitalWrite(waterPump, HIGH);    // WATER PUMP : OFF
}

void loop() {

  if (idle == 0) {
    if (calibrate == 1 && water == 0 && seed == 0) {
      AGE.beginCalbiration();
      Serial.println("Calibrate: " + String(calibrate) + " Water: " + String(water) + " Seed: " + String(seed));
    } else if (calibrate == 0 && water == 0 && seed == 1) {
      AGE.beginSeedDistribution();
      Serial.println("Calibrate: " + String(calibrate) + " Water: " + String(water) + " Seed: " + String(seed));
    } else if (calibrate == 0 && water == 1 && seed == 0) {
      AGE.beginWateringProcess();
      Serial.println("Calibrate: " + String(calibrate) + " Water: " + String(water) + " Seed: " + String(seed));
    } else if (calibrate == 0 && water == 0 && seed == 0) {
      idle = 1;
    }  else {
      Serial.println("ERROR. Can only execute one command per run.");
    }
  } else if (DONE == 0 && idle == 1) {
    Serial.println("Nothing to do.");
    DONE = 1;
    delay(15000);
  } else if (DONE == 1 && idle == 1) {

    if (digitalRead(seedPin) == HIGH && digitalRead(waterPin) == LOW && digitalRead(calibPin) == LOW) {
      Serial.println("Seed pin set to HIGH.");
      calibrate = 0;
      seed = 1;
      water = 0;
      idle = 0;
      DONE = 0;
      delay(1000);
    } else if (digitalRead(seedPin) == LOW && digitalRead(waterPin) == HIGH && digitalRead(calibPin) == LOW) {
      Serial.println("Water pin set to HIGH.");
      calibrate = 0;
      seed = 0;
      water = 1;
      idle = 0;
      DONE = 0;
      delay(1000);
    } else if (digitalRead(seedPin) == LOW && digitalRead(waterPin) == LOW && digitalRead(calibPin) == HIGH) {
      Serial.println("Calibrate pin set to HIGH.");
      calibrate = 1;
      seed = 0;
      water = 0;
      idle = 0;
      DONE = 0;
      delay(1000);
    }
    else {
      Serial.println("No tasks assigned.");
    }
  }

}
