// STEP PINS
extern int X_STP      = 2;
extern int Y_STP      = 3;
extern int Z_STP      = 4;

// DIRECTION PINS
extern int X_DIR      = 5;
extern int Y_DIR      = 6;
extern int Z_DIR      = 7;

// ENABLE PIN
extern int EN         = 8;

// LIMIT PINS
extern int X_LIM      = 9;
extern int Y_LIM      = 10;
extern int Z_LIM      = 11;

// GROW LIGHTS
extern int NeoPin_1   = 31;
extern int NeoPin_2   = 33;
extern int NeoPin_3   = 35;
extern int NeoPin_4   = 37;

// RPI-ARDUINO COMMUNICATION PINS
extern int modePin0   =  22;               // MODE SELECTION:    00 - 5 X 2;   10 - 6 X 3
extern int modePin1   =  23;               //                    01 - 4 X 2;   11 - 4 X 3    
extern int lightPin   =  39;               // FOR GROWLIGHTS
extern int seedPin    =  38;               // FOR SEEDING
extern int waterPin   =  40;               // FOR WATERING
extern int calibPin   =  42;               // FOR CALIBRATION

// PUMPS
extern int waterPump  =  48;
extern int vacuumPump =  49;
