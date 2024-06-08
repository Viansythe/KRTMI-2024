//-------------------------   MOTOR DC  ------------------------------
#define ENA1 12
#define R1M1 14 // M1
#define R1M2 27
#define L1M1 26 // M2
#define L1M2 25
#define ENB1 33

#define ENA2 23
#define R2M1 15 // M3
#define R2M2 18
#define L2M1 19 // M4
#define L2M2 21
#define ENB2 22

#define ENA3 5
#define R3M1 4
#define R3M2 0

#define RST 17

int battery = 0;

int angle1 = 90; // Posisi awal servo 1
int angle2 = 90; // Posisi awal servo 2

int a;

const int motorFreq = 5000;
const int motorResolution = 8;

const int motorAChannel = 2;
const int motorBChannel = 3;
const int motorCChannel = 4;
const int motorDChannel = 5;
const int motorEChannel = 6;


int leftX = 0;
int leftY = 0;
int rightX = 0;
int rightY = 0;

int sp = 200;

//-------------------------   SERVO  ------------------------------
Servo s1;
Servo s2;
Servo s3;
