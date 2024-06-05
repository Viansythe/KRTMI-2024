#include <Servo.h>
#include <TimerOne.h>
Servo myservo;
Servo servo1;
Servo servo2;
#define EN 44
#define ENA 46
#define STP_1 27 // STP_1 & DIR_1 = X
#define DIR_1 26
#define STP_2 29 // STP_2 & DIR_2 = Y
#define DIR_2 28
#define STP_3 31 // STP_3 & DIR_3 = Z
#define DIR_3 30
const int relayPin = 25;

volatile int steps1 = 0;
volatile int steps2 = 0;
volatile int steps3 = 0;

volatile int steps1_value = 0, steps2_value = 0, steps3_value = 0;
volatile bool moving = false;

unsigned long startTime;
unsigned long interval1 = 1200; // First interval duration in milliseconds
unsigned long interval2 = 2000; // Second interval duration in milliseconds

unsigned long startTime2;
unsigned long interval21 = 800; // First interval duration in milliseconds
unsigned long interval22 = 4000; // Second interval duration in milliseconds

int ok = 1;
int i;

void step (boolean dir, byte dirPin, byte stepperPin, volatile int& steps)
{
  digitalWrite (dirPin, dir);
  steps = 0;
  moving = true;
  startTime = millis(); // Record the start time when stepping starts

}

void adjustTimer3Interval() {
  unsigned long elapsedTime = millis() - startTime;
  if (elapsedTime < interval1) {
    Timer1.initialize(370);
  }
  else if (elapsedTime < interval2) {
    Timer1.initialize(200);
  }
  else {
    Timer1.initialize(180); // Default or final speed
  }
  if (steps3 < 2000) {
    Timer1.initialize(350);
  }
  else if (steps3 < 1000) {
    Timer1.initialize(600);
  }
  else if (steps3 < 2500) {
    Timer1.initialize(300);
  }
}

void adjustTimer2Interval() {
  unsigned long elapsedTime2 = millis() - startTime2;
  if (elapsedTime2 < interval21) {
    Timer1.initialize(370);
  }
  //  else if (elapsedTime < interval2) {
  //    Timer1.initialize(200);
  //  }
  else {
    Timer1.initialize(280); // Default or final speed
  }
  if (steps2 < 700) {
    Timer1.initialize(300);
  }
}

void adjustTimer3Intervalserial(volatile int steps, volatile int valuee) {
  //  Serial.print("    st:");Serial.print(steps); Serial.print("    ");
  unsigned long elapsedTime = millis() - startTime;
  int mid = valuee / 2; int akhir = valuee - mid; int baru = map(steps, valuee, mid, 300, 60);
  //  baru = constrain(baru,40,235);
  //  Serial.print("atas:");
  //  Serial.print(baru); Serial.print("       ");Serial.println(mid);
  if (steps <= mid) {
    int neww = mid - steps;
    baru = map(neww, 0, mid, 80, 300);
    Timer1.initialize(baru);
    //        Serial.print("neww:");Serial.print(neww);
    //        Serial.print("  2   ");Serial.println(baru);
  }
  //  else if (elapsedTime < interval2) {
  //    Timer1.initialize(200);
  //  }
  else {
    Timer1.initialize(baru); // Default or final speed
    //    Serial.print("    else:");Serial.println(baru);
    //    Serial.print("  2   ");
  }
  //  if (steps3 < 2000) {
  //    Timer1.initialize(350);
  //  }
}

//void adjustTimer3Interval(volatile int steps, volatile int valuee) {
//  unsigned long elapsedTime = millis() - startTime;
//  int mid = valuee / 2; int akhir = valuee - mid; int baru = map(steps, valuee, mid, 300, 60);
//  if (steps <= mid) {
//    int neww = mid - steps;
//    baru = map(neww, 0, mid, 80, 300);
//    Timer1.initialize(baru);
//  }
//  else {
//    Timer1.initialize(baru);
//  }
//}

void timerIsr() {
  if (moving) {
    if (steps1 > 0) {
      digitalWrite(STP_1, !digitalRead(STP_1));
      steps1--;
      Timer1.initialize(80);
    }
    if (steps2 > 0) {
      digitalWrite(STP_2, !digitalRead(STP_2));
      steps2--;
      adjustTimer2Interval();

    }
    if (steps3 > 0) {
      digitalWrite(STP_3, !digitalRead(STP_3));
      steps3--;
      //      Timer1.initialize(370);
      //      adjustTimer3Intervalserial(steps3, steps3_value);
      adjustTimer3Interval();
    }
    if (steps1 == 0 && steps2 == 0 && steps3 == 0) {
      moving = false;
    }
  }
}

void eksekusi(bool TF_A, bool TF_B, bool TF_C, int nA, int nB, int nC) {
  if (ok == 1) {
    step(TF_A, DIR_1, STP_1, steps1);
    steps1 = nA * 2;
    step(TF_B, DIR_2, STP_2, steps2);
    steps2 = nB * 2;
    step(TF_C, DIR_3, STP_3, steps3);
    steps3 = nC * 2;
    steps3_value = nC * 2;
    while (moving) delay(1);
    delay(500);
  }
  ok = 0;
}

void serv(int k, int a) {


  if (a <= k) {
    for (i = a; i <= k; i++) {
      servo1.write(i);
      servo2.write(i);
      delay(25);
    }
  }
  else {
    for (i = a; i >= k; i--) {
      servo1.write(i);
      servo2.write(i);
      delay(25);
    }
  }
}



void ambil(int srv, bool rly, int srv1) {
  myservo.write(srv);
  delay(500);
  digitalWrite(relayPin, rly);
  delay(500);
  myservo.write(srv1);
}

void buang(bool rly, int srv, int srv1) {
  digitalWrite(relayPin, rly);
  delay(500);
  myservo.write(srv);
  delay(500);
  myservo.write(srv1);
}

void setup () {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  myservo.attach(A5); servo1.attach(A7); servo2.attach(A6);
  myservo.write(0); servo1.write(89); servo2.write(89);
  Serial.begin (115200);
  pinMode(STP_1, OUTPUT); pinMode(DIR_1, OUTPUT);
  pinMode(STP_2, OUTPUT); pinMode(DIR_2, OUTPUT);
  pinMode(STP_3, OUTPUT); pinMode(DIR_3, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(ENA, OUTPUT);
  digitalWrite (EN, LOW);
  Timer1.initialize(370); // Set timer to 1ms interval
  Timer1.attachInterrupt(timerIsr); // Attach ISR to timer

}

void srl(int srv, bool rly, int srv1) {
  delay(0);
  myservo.write(srv);
  delay(0);
  digitalWrite(relayPin, rly);
  delay(0);
  myservo.write(srv1);
}


// note
// STP1 false = maju , true= mundur X
// STP2 false = kiri, true = kanan  Y
// STP3 false = kiri, true = kanan  Z
void loop () {
  //
  //ok = 1;
  //eksekusi(true, true, true, 0, 5000, 0);
  //delay(2000);
  //ok = 1;
  //eksekusi(true, false, true, 0, 5000, 0);
  //delay(2000);

  if (ok == 1) {

    // PLAN A

    //Ambil sampah 6    //Sampah 1
    eksekusi(true, true, true, 900, 2500, 5000);
    ambil(180, LOW, 0);
    //BUANG KE DAUN
//    delay(500);
//    ok = 1;
//    eksekusi(false, false, false, 5700, 6000, 5000);
    buang(HIGH, 1, 0);
//    //AMBIL SAMPAH 4    //Sampah 2
//    delay(500);
//    ok = 1;
//    eksekusi(true, true, true, 6000, 0, 0);
//    ambil(180, LOW, 0);
//    //BUANG KE KERTAS
//    delay(500);
//    ok = 1;
//    eksekusi(false, true, true, 6000, 4500, 0);
//    buang(HIGH, 1, 0);
//    //AMBIL SAMPAH 5    //Sampah 3
//    delay(700);
//    ok = 1;
//    eksekusi(true, true, true, 11500, 1300, 0);
//    ambil(180, LOW, 0);
//    //BUANG KE PLASTIK
//    delay(700);
//    ok = 1;
//    eksekusi(false, true, true, 11500, 0, 3000);
//    buang(HIGH, 1, 0);
//    //AMBIL SAMPAH 7    //Sampah 4
//    delay(500);
//    ok = 1;
//    eksekusi(true, true, true, 11500, 0, 8300);
//    ambil(180, LOW, 0);
//    //BUANG KE FERO
//    delay(500);
//    ok = 1;
//    eksekusi(false, true, true, 11500, 0, 0);
//    buang(HIGH, 1, 0);
//    //AMBIL SAMPAH 8    //Sampah 5
//    delay(700);
//    ok = 1;
//    eksekusi(true, true, true, 6200, 600, 4800);
//    ambil(180, LOW, 0);
//    //BUANG KE KERTAS
//    delay(500);
//    ok = 1;
//    eksekusi(false, false, false, 6200, 7000, 11900);
//    buang(HIGH, 1, 0);
//    //AMBIL SAMPAH 3    //Sampah 6
//    delay(500);
//    ok = 1;
//    eksekusi(true, false, false, 11500, 0, 9900);
//    ambil(180, LOW, 0);
//    //BUANG KE PLASTIK
//    delay(800);
//    ok = 1;
//    eksekusi(false, true, true, 11500, 8000, 6800);
//    buang(HIGH, 1, 0);
//    //AMBIL SAMPAH 2    //Sampah 7
//    delay(500);
//    ok = 1;
//    serv(30, 88);
//    eksekusi(true, false, false, 0, 8000, 1450);
//    ambil(180, LOW, 0);
//    // BUANG KE NON-FERO
//    delay(500);
//    ok = 1;
//    serv(88, 30);
//    eksekusi(false, true, true, 0, 8000, 5250);
//    buang(HIGH, 1, 0);
//    //AMBIL SAMPAH 10    //Sampah 8
//    delay(500);
//    ok = 1;
//    serv(142, 88);
//    eksekusi(false, true, true, 0, 0, 10950);
//    ambil(180, LOW, 0);
//    //BUANG KE PLASTIK
//    delay(700);
//    ok = 1;
//    serv(88, 144);
//    eksekusi(false, false, false, 0, 8000, 6700);
//    buang(HIGH, 1, 0);
//    //AMBIL SAMPAH 10   //Sampah 9
//    delay(500);
//    ok = 1;
//    serv(167, 88);
//    eksekusi(false, true, true, 0, 6800, 0);
//    ambil(180, LOW, 0);
//    //BUANG KE PLASTIKw
//    delay(500);
//    ok = 1;
//    serv(88, 167);
//    eksekusi(false, false, false, 0, 5400, 2000); //cek fulu
//    buang(HIGH, 1, 0);
//    //AMBIL SAMPAH 1    //Sampah 10
//    delay(500);
//    ok = 1;
//    serv(5, 88);
//    eksekusi(false, false, false, 0, 0, 11300);
//    ambil(180, LOW, 0);
//    //BUANG KE DAUN
//    delay(500);
//    ok = 1;
//    serv(88, 3);
//    eksekusi(false, true, true, 0, 4250, 0);
//    buang(HIGH, 1, 0);
  }
  ok = 0;
}
