class Commands {

  private:

  public:

    // 3-AXIS CALIBRATION
    void beginCalbiration() {

      if (axis == 'X') {          // X-AXIS CALIBRATION

        if (digitalRead(X_LIM) == HIGH && X_POS == false) {
          SMC.step(true, X_DIR, X_STP, stps);
          Serial.println("MOVING X-AXIS TO THE RIGHT.");
        } else if (digitalRead(X_LIM) == LOW && X_POS == false) {
          Serial.println("X_POS TOUCHED");
          X_POS = true;
          if (X_POS == true) {
            SMC.step(false, X_DIR, X_STP, stps);    // GO BACK ONE STEP
          }
          delay(1000);
        } else if (digitalRead(X_LIM) == HIGH && X_NEG == false) {
          SMC.step(false, X_DIR, X_STP, stps);
          Serial.println("MOVING X-AXIS TO THE LEFT.");
        } else if (digitalRead(X_LIM) == LOW && X_NEG == false) {
          Serial.println("X_NEG TOUCHED");
          delay(1000);
          Serial.println("Now stopping motion along X-AXIS.");
          X_NEG = true;
          delay(1000);
        } else if (X_POS == true && X_NEG == true) {
          Serial.println("MOTION ALONG X-AXIS STOPPED.");
          Serial.println("X-AXIS SUCCESSFULLY CALIBRATED.");
          delay(3000);
          axis = 'Y';
        }

      } else if (axis == 'Y') {   // Y-AXIS CALIBRATION

        if (digitalRead(Y_LIM) == HIGH && Y_POS == false) {
          SMC.step(true, Y_DIR, Y_STP, stps);
          Serial.println("MOVING Y-AXIS UPWARD.");
        } else if (digitalRead(Y_LIM) == LOW && Y_POS == false) {
          Serial.println("Y_POS TOUCHED");
          Y_POS = true;
          if (Y_POS == true) {
            SMC.step(false, Y_DIR, Y_STP, stps);    // GO BACK ONE STEP
          }
          delay(1000);
        } else if (digitalRead(Y_LIM) == HIGH && Y_NEG == false) {
          SMC.step(false, Y_DIR, Y_STP, stps);
          Serial.println("MOVING Y-AXIS DOWNWARD.");
        } else if (digitalRead(Y_LIM) == LOW && Y_NEG == false) {
          Serial.println("Y_NEG TOUCHED");
          delay(1000);
          Serial.println("Now stopping motion along Y-AXIS.");
          Y_NEG = true;
          delay(1000);
        } else if (Y_POS == true && Y_NEG == true) {
          Serial.println("MOTION ALONG Y-AXIS STOPPED.");
          Serial.println("Y-AXIS SUCCESSFULLY CALIBRATED.");
          delay(3000);

          // CALIBRATION FINISHED
          calibrate = 0;
          seed = 0;
          Serial.println("XYZ ROBOT CALIBRATED SUCCESSFULLY");
          water = 0;        //PARA MAGWATER AFTER

          // RESET LIMIT SWTICH CHECKERS
          X_POS = false;
          X_NEG = false;
          Y_POS = false;
          Y_NEG = false;
          Z_POS = false;
          Z_NEG = false;
        }
      }
    }

    // FINALIZE ONLY IF ALAM NA SAN ILALAGAY YUNG SEED TRAY
    void beginSeedDistribution() {

      mode.check();
      mode.assign();

      // PRINT STARTING COORDINATES
      Serial.println((String)"START \n    --> X : " + X_VAL + (String)" CM , Y : " + Y_VAL +  (String)" CM , Z : " + Z_VAL + (String)" CM");

      // MOVE TO FIRST LOCATION
      SMC.step(true, X_DIR, X_STP, stps * (xStart - X_MIN));
      Serial.println((String)"X MOVED " + (xStart - X_MIN) + (String)" CM.");
      SMC.step(true, Y_DIR, Y_STP, stps * (ySeed - Y_MIN));
      Serial.println((String)"Y MOVED " + (ySeed - Y_MIN) + (String)" CM.");
      //Serial.println(xStart - X_MIN);
      //delay(1000000);

      Serial.println("Seeding process finished.");
      calibrate = 0;    // for demo
      seed = 0;
      water = 0;
    }



    // WATERING
    void beginWateringProcess() {

      mode.check();
      mode.assign();

      // PRINT STARTING COORDINATES
      Serial.println((String)"START \n    --> X : " + X_VAL + (String)" CM , Y : " + Y_VAL +  (String)" CM , Z : " + Z_VAL + (String)" CM");

      // MOVE TO FIRST ROW AND FIRST COLUMN
      SMC.step(true, X_DIR, X_STP, stps * (xStart - X_MIN));
      Serial.println((String)"X MOVED " + (xStart - X_MIN) + (String)" CM.");
      SMC.step(true, Y_DIR, Y_STP, stps * (yWater - Y_MIN));
      Serial.println((String)"Y MOVED " + (yWater - Y_MIN) + (String)" CM.");
      delay(5000);
      //delay(10000); //panglagay ng meter stick
      SMC.startWateringFIRST();

      // TRAVEL TO REMAINING COLUMNS
      for (int i = 1; i < noOfCols; i++) {
        SMC.step(true, X_DIR, X_STP, stps * xSpace);
        Serial.println((String)"X MOVED " + xSpace + (String)" CM.");
        delay(5000);
        SMC.startWatering();
      }

      // MOVE TO NEXT ROW
      SMC.step(true, Y_DIR, Y_STP, stps * ySpace);
      Serial.println((String)"Y MOVED " + ySpace + (String)" CM.");
      delay(5000);
      SMC.startWatering();


      for (int i = 1; i < noOfCols; i++) {
        SMC.step(false, X_DIR, X_STP, stps * xSpace);
        Serial.println((String)"X MOVED " + xSpace + (String)" CM.");
        delay(5000);
        SMC.startWatering();
      }

      if (digitalRead(modePin1) == 1) {
        // MOVE TO NEXT ROW
        SMC.step(true, Y_DIR, Y_STP, stps * ySpace);
        Serial.println((String)"Y MOVED " + ySpace + (String)" CM.");
      } else {

      }

      // MOVE TO LEFTMOST END ALONG X
      SMC.step(false, X_DIR, X_STP, stps * (xStart - X_MIN));
      Serial.println((String)"X MOVED " + (xStart - X_MIN) + (String)" CM.");

      // MOVE BACK TO ORIGIN
      for (int i = 1; i < noOfRows; i++) {
        SMC.step(false, Y_DIR, Y_STP, stps * ySpace);
        Serial.println((String)"Y MOVED " + ySpace + (String)" CM.");
      }

      SMC.step(false, Y_DIR, Y_STP, stps * (yWater - Y_MIN));
      Serial.println((String)"Y MOVED " + (yWater - Y_MIN) + (String)" CM.");

      Serial.println("Watering process finished.");
      calibrate = 0;    // for demo
      water = 0;
      seed = 0;
    }


};

Commands AGE;
