//#include "Declarations.h"

class Commands {

  private:
    
  public:
    
//    int X_DIR;
//    int X_STP;
//    int stps;
    
    void beginCalbiration(){

//      if(axis == 'X'){
//        Serial.println((String)"Hello there. X-AXIS BEING CALIBRATED.");
//        X_DIR = 5;
//        delay(2000);
//      } 
      
      SMC.step(true, X_DIR, X_STP, stps);
      if(X_DIR == 5){
         Serial.println((String)"Hello there."); 
         Serial.println(X_STP);      
      }
     }

}; 

Commands AGE; 
