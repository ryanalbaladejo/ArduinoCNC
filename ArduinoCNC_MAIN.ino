#include "Controls.h"
#include "ModeSelection.h"
#include "Commands.h"
#include <Adafruit_NeoPixel.h>

//#define NeoPin_1 31
//#define NeoPin_2 33
//#define NeoPin_3 35
//#define NeoPin_4 37
//#define NUMPIXELS 178
//#define lightPin 39

Adafruit_NeoPixel pixels1(NUMPIXELS, NeoPin_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, NeoPin_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS, NeoPin_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS, NeoPin_4, NEO_GRB + NEO_KHZ800);


// FOR TESTING PURPOSES:    1. Go to Constants.h and look for section "// RPI HARDCODED COMMANDS".
//                          2. Select the process you wish to perform on the robot and change the
//                             value 0 -> 1. (PICK ONE ONLY)
//                          3. After selecting the process, go to ModeSelection.h and replace the
//                             argument in one of the if/else in check() with the process you selected.
//                          4. Set modeSelected into the mode setting you wish to apply. [Input 1/2/3/4]
//
//                             ADDITIONAL STEP IF SEEDING/WATERING:
//                             a. Press Ctrl+F on Commands.h and search for:
//                                    "[FOR TESTING IN WATERING]" - if watering is being tested
//                                    "[FOR TESTING IN SEEDING]" - if seeding is being tested
//                             b. Change the argument to "seed = 1" or "water = 1" depending on the
//                                process being simulated.
//
//                                EXAMPLE:
//
//                                Scenario: You wish to perform the watering process with the robot
//                                          and you want it to use the 6 x 3 setting [MODE 3].
//
//                                - Set < calibrate = "1" > under Constants.h
//                                - Replace argument containing modeSelected = 1 with < water == "1" >
//
//                                    FROM    if (digitalRead(modePin1) == 0 && digitalRead(modePin0) == 0)
//                                    TO      if (water == "1")
//
//                                - Replace value of modeSelected = 1 to 2 (4 x 2) / 3 (6 x 3) / 4 (4 x 3)
//                                - Upload and run the program.

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
  pinMode(vacuumPump, OUTPUT);

  pinMode(EN, OUTPUT);

  pinMode(X_LIM, INPUT_PULLUP);
  pinMode(Y_LIM, INPUT_PULLUP);
  pinMode(Z_LIM, INPUT_PULLUP);

  digitalWrite(EN, LOW);
  digitalWrite(waterPump, HIGH);    // WATER PUMP : OFF
  digitalWrite(vacuumPump, HIGH);   // VACUUM PUMP : OFF

  pixels1.begin();
  pixels2.begin();
  pixels3.begin();
  pixels4.begin();
}

void loop() {

  if (idle == 0) {
    if (calibrate == 1 && water == 0 && seed == 0) {
      AGE.beginCalbiration();
      //Serial.println("Calibrate: " + String(calibrate) + " Water: " + String(water) + " Seed: " + String(seed));    //FOR DEBUGGING
    } else if (calibrate == 0 && water == 0 && seed == 1) {
      AGE.beginSeedDistribution();
      //Serial.println("Calibrate: " + String(calibrate) + " Water: " + String(water) + " Seed: " + String(seed));    //FOR DEBUGGING
    } else if (calibrate == 0 && water == 1 && seed == 0) {
      AGE.beginWateringProcess();
      //Serial.println("Calibrate: " + String(calibrate) + " Water: " + String(water) + " Seed: " + String(seed));    //FOR DEBUGGING
    } else if (calibrate == 0 && water == 0 && seed == 0) {
      idle = 1;
    }  else {
      Serial.println("ERROR. Can only execute one command per run.");
    }
  } else if (DONE == 0 && idle == 1) {
    if (digitalRead(lightPin) == HIGH) {
      // TURN ON GROW LIGHTS
      for (int i = 0; i < NUMPIXELS; i++) {
        if (i % 4 == 0) {
          pixels1.setPixelColor(i, pixels1.Color(0, 0, 255));
          pixels2.setPixelColor(i, pixels2.Color(0, 0, 255));
          pixels3.setPixelColor(i, pixels3.Color(0, 0, 255));
          pixels4.setPixelColor(i, pixels4.Color(0, 0, 255));
          pixels1.show();
          pixels2.show();
          pixels3.show();
          pixels4.show();
        }
        else {
          pixels1.setPixelColor(i, pixels1.Color(255, 0, 0));
          pixels2.setPixelColor(i, pixels2.Color(255, 0, 0));
          pixels3.setPixelColor(i, pixels3.Color(255, 0, 0));
          pixels4.setPixelColor(i, pixels4.Color(255, 0, 0));
          pixels1.show();
          pixels2.show();
          pixels3.show();
          pixels4.show();
        }
      }
    } else {
      // TURN OFF GROW LIGHTS
      for (int i = 0; i < NUMPIXELS; i++) {
        pixels1.setPixelColor(i, pixels1.Color(0, 0, 0));
        pixels2.setPixelColor(i, pixels2.Color(0, 0, 0));
        pixels3.setPixelColor(i, pixels3.Color(0, 0, 0));
        pixels4.setPixelColor(i, pixels4.Color(0, 0, 0));
        pixels1.show();
        pixels2.show();
        pixels3.show();
        pixels4.show();
      }
    }

    Serial.println("Nothing to do.");
    DONE = 1;
    delay(3000);

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
      delay(1000);
      calibrate = 1;
      water = 0;
      seed = 0;
      DONE = 0;
      idle = 0;
    }
  }

}
