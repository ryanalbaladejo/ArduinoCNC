class Commands {

  private:
    
  public:
    
    // 3-AXIS CALIBRATION
    void beginCalbiration(){

      if(axis == 'X'){
        
        if(digitalRead(X_LIM) == HIGH && X_POS == false){  
          SMC.step(true, X_DIR, X_STP, stps);
          Serial.println("MOVING X-AXIS TO THE RIGHT.");
        } else if(digitalRead(X_LIM) == LOW && X_POS == false){
          Serial.println("X_POS TOUCHED");
          X_POS = true;
          delay(3000);
        } else if(digitalRead(X_LIM) == HIGH && X_NEG == false){
          SMC.step(false, X_DIR, X_STP, stps);
          Serial.println("MOVING X-AXIS TO THE LEFT.");
        } else if(digitalRead(X_LIM) == LOW && X_NEG == false){
          Serial.println("X_NEG TOUCHED");
          delay(1000);
          //SMC.step(false, X_DIR, X_STP, 0);
          Serial.println("Now stopping motion along X-AXIS.");
          X_NEG = true;
          delay(3000);
        } else if (X_POS == true && X_NEG == true){
          Serial.println("MOTION ALONG X-AXIS STOPPED.");
          Serial.println("X-AXIS SUCCESSFULLY CALIBRATED.");
          //SMC.step(false, X_DIR, X_STP, 0);
          delay(5000);
          axis = 'Y';
        }
        
      } else if(axis == 'Y'){
        
        if(digitalRead(Y_LIM) == HIGH && Y_POS == false){  
          SMC.step(true, Y_DIR, Y_STP, stps);
          Serial.println("MOVING Y-AXIS UPWARD.");
        } else if(digitalRead(Y_LIM) == LOW && Y_POS == false){
          Serial.println("Y_POS TOUCHED");
          Y_POS = true;
          delay(3000);
        } else if(digitalRead(Y_LIM) == HIGH && Y_NEG == false){
          SMC.step(false, Y_DIR, Y_STP, stps);
          Serial.println("MOVING Y-AXIS DOWNWARD.");
        } else if(digitalRead(Y_LIM) == LOW && Y_NEG == false){
          Serial.println("Y_NEG TOUCHED");
          delay(1000);
          //SMC.step(false, Y_DIR, Y_STP, 0);
          Serial.println("Now stopping motion along Y-AXIS.");
          Y_NEG = true;
          delay(3000);
        } else if (Y_POS == true && Y_NEG == true){
          Serial.println("MOTION ALONG Y-AXIS STOPPED.");
          Serial.println("Y-AXIS SUCCESSFULLY CALIBRATED.");
          //SMC.step(false, Y_DIR, Y_STP, 0);
          delay(5000);
         
          calibrate = 0;

          // RESET LIMIT SWTICH CHECKERS
          X_POS = false;
          X_NEG = false;
          Y_POS = false;
          Y_NEG = false;
        }
      }   
    }
     

}; 

Commands AGE; 
