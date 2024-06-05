// Motor control pin RPWM1 2
int RPWM1 = 2;
int LPWM1 = 3;
int RPWM2 = 4;
int LPWM2 = 5;
int RPWM3 = 6;
int LPWM3 = 7;
int RPWM4 = 8;
int LPWM4 = 9;

int spd=50;

void setup() {
  // Set pin as output
  pinMode(RPWM1, OUTPUT);
  pinMode(LPWM1, OUTPUT);
  pinMode(RPWM2, OUTPUT);
  pinMode(LPWM2, OUTPUT);
  pinMode(RPWM3, OUTPUT);
  pinMode(LPWM3, OUTPUT);
  pinMode(RPWM4, OUTPUT);
  pinMode(LPWM4, OUTPUT);

  // Open serial communication for debugging
  Serial.begin(115200);
}

void loop(){
  luruskiri();
  delay(1000);
  }
void maju() {
  analogWrite(LPWM1, spd);
  analogWrite(RPWM1, 0);
  analogWrite(LPWM2, 0);
  analogWrite(RPWM2, spd);
  analogWrite(LPWM3, spd);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM4, spd);
  analogWrite(RPWM4, 0);
}

// Function to move the robot forward
void luruskanan() {
  analogWrite(LPWM1, 0);
  analogWrite(RPWM1, spd);
  analogWrite(LPWM2, 0);
  analogWrite(RPWM2, spd);
  analogWrite(LPWM3, spd);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM4, 0);
  analogWrite(RPWM4, spd);
}

void mundurkanan() {
  analogWrite(LPWM1, 0);
  analogWrite(RPWM1, spd);
  analogWrite(LPWM2, 0);
  analogWrite(RPWM2, spd);
  analogWrite(LPWM3, 0);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM4, 0);
  analogWrite(RPWM4, 0);
}

// Function to move the robot forward
void luruskiri() {
  analogWrite(LPWM1, spd);
  analogWrite(RPWM1, 0);
  analogWrite(LPWM2, spd);
  analogWrite(RPWM2, 0);
  analogWrite(LPWM3, 0);
  analogWrite(RPWM3, spd);
  analogWrite(LPWM4, spd);
  analogWrite(RPWM4, 0);
}
void mundurkiri() {
  analogWrite(LPWM1, 0);
  analogWrite(RPWM1, 10);
  analogWrite(LPWM2, 0);
  analogWrite(RPWM2, 10);
  analogWrite(LPWM3, spd);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM4, spd);
  analogWrite(RPWM4, 0);
}

// Function to turn the robot to the right
void kanan() {
  analogWrite(LPWM1, 0);
  analogWrite(RPWM1, spd);
  analogWrite(LPWM2, 0);
  analogWrite(RPWM2, spd);
  analogWrite(LPWM3, spd);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM4, spd);
  analogWrite(RPWM4, 0);
}

// Function to turn the robot to the left
void kiri() {
  analogWrite(LPWM1, spd);
  analogWrite(RPWM1, 0);
  analogWrite(LPWM2, spd);
  analogWrite(RPWM2, 0);
  analogWrite(LPWM3, 0);
  analogWrite(RPWM3, spd);
  analogWrite(LPWM4, 0);
  analogWrite(RPWM4, spd);
}

void mundur() {
  analogWrite(LPWM1, 0);
  analogWrite(RPWM1, spd);
  analogWrite(LPWM2, 0);
  analogWrite(RPWM2, spd);
  analogWrite(LPWM3, spd);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM4, spd);
  analogWrite(RPWM4, 0);
}

// Function to stop all motors
void mati() {
  analogWrite(LPWM1, 0);
  analogWrite(RPWM1, 0);
  analogWrite(LPWM2, 0);
  analogWrite(RPWM2, 0);
  analogWrite(LPWM3, 0);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM4, 0);
  analogWrite(RPWM4, 0);
}

void stop2() {
  analogWrite(LPWM1, 0);
  analogWrite(RPWM1, spd);
  analogWrite(LPWM2, 0);
  analogWrite(RPWM2, spd);
  analogWrite(LPWM3, spd);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM4, spd);
  analogWrite(RPWM4, 0);
}
