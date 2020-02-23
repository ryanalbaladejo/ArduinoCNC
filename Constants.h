// STEPPER MOTOR SETTINGS
extern int delayTime = 1000;         //Delay between each pause (uS); The smaller the value, the faster the revolution.
extern long int stps = 50;           // microsteps per revolution with 1/32 microstepping    [50 steps = 1 cm travel]

// LIMIT SWITCH CHECKERS
extern boolean X_POS = false;    // X RIGHT LIMIT SWITCH
extern boolean X_NEG = false;    // X LEFT LIMIT SWITCH

extern boolean Y_POS = false;    // Y DOWN LIMIT SWITCH
extern boolean Y_NEG = false;    // Y UP LIMIT SWITCH

extern boolean Z_POS = false;
extern boolean Z_NEG = false;

//  MOTOR COORDINATES
extern long int X_VAL = 0;
extern long int Y_VAL = 0;
extern long int Z_VAL = 0;

// AXIS
extern char axis = 'X';

// RPI HARDCODED COMMANDS
extern int calibrate = 1;

// IDLE
extern boolean idle = 0;
