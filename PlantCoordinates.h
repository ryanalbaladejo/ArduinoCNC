extern int xStart       = 0;
extern int yStart       = 0;
extern int xSpace       = 0;
extern int ySeed        = 0;
extern int yWater       = 0;


// MODE 00: 5 X 2

extern int  MODE00_xSpace = 15;           // SPACING ALONG X
extern int  MODE00_xStart = 16;           // FIRST X-COORDINATE

extern int  MODE00_ySpace = 20;           // SPACING ALONG Y
extern int  MODE00_ySeed = 15;            // FIRST Y-COORDINATE FOR SEEDING
extern int  MODE00_yWater = 22;           // FIRST Y-COORDINATE FOR WATERING

extern int  MODE00_noOfColumns = 5;
extern int  MODE00_noOfRows = 2;


//X = 16, 31, 46, 61, 76, 91  // 15cm distance
//    seedY = 15, 35;             // 20cm distance
//waterY = 22, 42;
//
//// MODE 01: 4 X 2
//
//X = 25, 45, 65, 85          // 20cm distance
//    seedY = 15, 35;             // 20cm distance
//waterY = 22, 42;
//
//// MODE 10: 6 X 3
//
//X = 20, 32, 44, 56, 68, 80, 92    // 12cm distance
//    seedY = 15, 25, 35;               // 10cm distance
//waterY = 22, 32, 42;
//
//// MODE 11: 4 X 3
//
//X = 25, 45, 65, 85          // 20cm distance
//    seedY = 15, 25, 35;         // 10cm distance
//waterY = 22, 32, 42;
