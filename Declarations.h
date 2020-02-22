// STEP PINS
extern int X_STP  = 2;
extern int Y_STP  = 3;
extern int Z_STP  = 4;

// DIRECTION PINS
extern int X_DIR  = 5;
extern int Y_DIR  = 6;
extern int Z_DIR  = 7;

// ENABLE PIN
extern int EN     = 8;

// LIMIT PINS
extern int X_LIM  = 9;
extern int Y_LIM  = 10;
extern int Z_LIM  = 11;

// RPI-ARDUINO COMMUNICATION PINS
extern int seedPin0 ;     //FOR SEEDING:    00 - 5 X 2;   10 - 6 X 2
extern int seedPin1 ;     //                01 - 4 X 2    11 - 3 X 2
extern int waterPin ;     //FOR WATERING:
extern int calibPin ;     //FOR CALIBRATION

extern int delayTime = 1000;         //Delay between each pause (uS) 
extern long int stps = 50;           // microsteps per revolution with 1/32 microstepping    [50 steps = 1 cm travel]
