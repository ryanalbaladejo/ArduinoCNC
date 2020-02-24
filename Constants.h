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

// MAX / MIN REACH FOR EACH AXIS

extern long int X_MIN = 15;
extern long int X_MAX = 95;

extern long int Y_MIN = 12;
extern long int Y_MAX = 43;

extern long int Z_MIN = 0;
extern long int Z_MAX = 0;

// MOTOR COORDINATES AFTER SUCCESSFUL CALIBRATION

extern long int X_VAL = X_MIN;
extern long int Y_VAL = Y_MIN;
extern long int Z_VAL = Z_MIN;

// AXIS

extern char axis = 'X';

// RPI HARDCODED COMMANDS

extern int calibrate = 0;
extern int water     = 0;
extern int seed      = 0;

// IDLE

extern boolean idle = 0;
extern boolean DONE = 0;
