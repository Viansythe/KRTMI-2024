#include "var.h"
#include "planstepper.h"
#include "planA.h"
#include "planB.h"
#include "planC.h"
#include "planD.h"
#include "planE.h"
#include "planF.h"
#include "planG.h"
#include "planH.h"

void setup() {
  Serial.begin(115200);

  // Initialize motor control pins
  pinMode(RPWM1, OUTPUT); pinMode(LPWM1, OUTPUT);
  pinMode(RPWM2, OUTPUT); pinMode(LPWM2, OUTPUT);
  pinMode(RPWM3, OUTPUT); pinMode(LPWM3, OUTPUT);
  pinMode(RPWM4, OUTPUT); pinMode(LPWM4, OUTPUT);

  //Push button
  pinMode(btn1, OUTPUT);  pinMode(btn2, OUTPUT);
  pinMode(btn3, OUTPUT);  pinMode(btn4, OUTPUT);
  pinMode(btn5, OUTPUT);  pinMode(btn6, OUTPUT);
  pinMode(btn7, OUTPUT);  pinMode(btn8, OUTPUT);

  //  pinMode(start, INPUT_PULLUP);
  digitalWrite(btn1, HIGH); digitalWrite(btn2, HIGH);
  digitalWrite(btn3, HIGH); digitalWrite(btn4, HIGH);
  digitalWrite(btn5, HIGH); digitalWrite(btn6, HIGH);
  digitalWrite(btn7, HIGH); digitalWrite(btn8, HIGH);


  // Initialize ultrasonic sensor pins
  pinMode(trigPin1, OUTPUT);  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);  pinMode(echoPin2, INPUT);

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  myservo.attach(A5); servo1.attach(A7); servo2.attach(A6);
  myservo.write(0); servo1.write(89); servo2.write(89);
  pinMode(STP_1, OUTPUT); pinMode(DIR_1, OUTPUT);
  pinMode(STP_2, OUTPUT); pinMode(DIR_2, OUTPUT);
  pinMode(STP_3, OUTPUT); pinMode(DIR_3, OUTPUT);
  pinMode(EN, OUTPUT); pinMode(ENA, OUTPUT);
  digitalWrite (EN, LOW);
  //  eksekusi(true, true, true, 0, 0, 0);
  Timer1.initialize(370); // Set timer to 1ms interval
  Timer1.attachInterrupt(timerIsr); // Attach ISR to timer
}

// Function to control the robot based on sensor data and PID output
void controlRobot() {

  //  serv(89,0);

  while (objectDetected = true) {
    long distance1 = getDistance(trigPin1, echoPin1);
    long distance2 = getDistance(trigPin2, echoPin2);
    Serial.print("Distance Sensor 1: ");
    Serial.print(distance1);
    Serial.print(" cm, Distance Sensor 2: ");
    Serial.print(distance2);
    Serial.println(" cm");

    // Adjust speed based on distance
    if (distance1 <= 30 || distance2 <= 30) {
      spd = reducedSpeed;
    } else {
      spd = normalSpeed;
    }

    // Control logic based on PID output and ultrasonic sensor data
    if ((distance1 <= 16 && distance1 >= 15) && (distance2 <= 17 && distance2 >= 16)) {
      // Stop if an object is detected within stopDistance cm by either sensor
      Serial.println("Object detected. Stopping...");
      stop2(); delay(100);
      objectDetected = true;
      stopMotors();
      break;
    } else if (distance1 >= 15 && distance1 <= 16 && distance2 >= 18) {
      // Stop if an object is detected within stopDistance cm by either sensor
      Serial.println("maju kanan...");
      majukanan();
      if (distance2 <= 17 && distance2 >= 16) {
        stop2(); delay(100);
        objectDetected = true;
        stopMotors();
      }
    } else if (distance1 >= 17 && distance2 <= 17 && distance2 >= 16) {
      // Stop if an object is detected within stopDistance cm by either sensor
      Serial.println("maju kiri...");
      majukiri();
      if (distance1 <= 16 && distance1 >= 15) {
        stop2(); delay(100);
        objectDetected = true;
        stopMotors();
      }
    } else if (distance1 <= 16 && distance1 >= 15 && distance2 <= 15) {
      // Stop if an object is detected within stopDistance cm by either sensor
      Serial.println("mundur kanan...");
      mundurkanan();
      if (distance2 <= 17 && distance2 >= 16) {
        stop2(); delay(100);
        objectDetected = true;
        stopMotors();
      }
    } else if (distance1 <= 14 && distance2 <= 17 && distance2 >= 16) {
      // Stop if an object is detected within stopDistance cm by either sensor
      Serial.println("mundur kiri...");
      mundurkiri();
      if (distance1 <= 16 && distance1 >= 15) {
        stop2(); delay(100);
        objectDetected = true;
        stopMotors();
      }
    } else {
      // Move forward
      Serial.println("Move forward");
      moveForward();
    }
  }
  Serial.println("KELUAR!!!!!!!!!");
  stopMotors();
  //    serv(89,0);
}

// Function to move the robot forward
void majukanan() {
  analogWrite(LPWM1, spd);
  analogWrite(RPWM1, 0);
  analogWrite(LPWM2, spd);
  analogWrite(RPWM2, 0);
  analogWrite(LPWM3, 10);
  analogWrite(RPWM3, 0);
  analogWrite(LPWM4, 10);
  analogWrite(RPWM4, 0);
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
void majukiri() {
  analogWrite(LPWM1, 0);
  analogWrite(RPWM1, 0);
  analogWrite(LPWM2, 0);
  analogWrite(RPWM2, 0);
  analogWrite(LPWM3, 0);
  analogWrite(RPWM3, spd);
  analogWrite(LPWM4, 0);
  analogWrite(LPWM4, spd);
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

// Function to move the robot forward
void moveForward() {
  analogWrite(LPWM1, spd + 1);
  analogWrite(RPWM1, 0);
  analogWrite(LPWM2, spd + 1);
  analogWrite(RPWM2, 0);
  analogWrite(LPWM3, 0);
  analogWrite(RPWM3, spd );
  analogWrite(LPWM4, 0);
  analogWrite(RPWM4, spd );
}

// Function to turn the robot to the right
void turnRight() {
  analogWrite(LPWM1, spd);
  analogWrite(RPWM1, 0);
  analogWrite(LPWM2, spd);
  analogWrite(RPWM2, 0);
  analogWrite(LPWM3, 0);
  analogWrite(RPWM3, spd);
  analogWrite(LPWM4, 0);
  analogWrite(RPWM4, spd);
}

// Function to turn the robot to the left
void turnLeft() {
  analogWrite(LPWM1, spd);
  analogWrite(RPWM1, 0);
  analogWrite(LPWM2, spd);
  analogWrite(RPWM2, 0);
  analogWrite(LPWM3, 0);
  analogWrite(RPWM3, spd);
  analogWrite(LPWM4, 0);
  analogWrite(RPWM4, spd);
}

void moveBackward() {
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
void stopMotors() {
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

void loop() {
  //  controlRobot();
  //  planA();
  //  exit(0);

  //    planA();
  if (digitalRead(btn1) == LOW) {
    Serial.println("PLAN A");
    //    serv(90, 0);
    controlRobot();
    planA();
    exit(0);
  }
  else if (digitalRead(btn2) == LOW) {
    Serial.println("PLAN B");
    //    serv(90, 0);
    controlRobot();
    planB();
    exit(0);

  }
  else if (digitalRead(btn3) == LOW) {
    Serial.println("PLAN C");
    //    serv(90, 0);
    controlRobot();
    planC();
    exit(0);

  }
  else if (digitalRead(btn4) == LOW) {
    Serial.println("PLAN D");
    //    serv(90, 0);
  controlRobot();
    planD();
    exit(0);

  }
  else if (digitalRead(btn5) == LOW) {
    Serial.println("PLAN E");
    //    serv(90, 0);
    controlRobot();
    planE();
    exit(0);

  }
  else if (digitalRead(btn6) == LOW) {
    Serial.println("PLAN F");
    //    serv(90, 0);
   controlRobot();
    planF();
    exit(0);

  }
  else if (digitalRead(btn7) == LOW) {
    Serial.println("PLAN G");
    //    serv(90, 0);
    controlRobot();
    planG();
    exit(0);

  }
  else if (digitalRead(btn8) == LOW) {
    Serial.println("PLAN H");
    //    serv(90, 0);
    controlRobot();
    planH();
    exit(0);
  }
}
