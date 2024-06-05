#include <Servo.h>
#include <TimerOne.h>
int ok = 1;
int i;
const int relayPin = 25;
Servo myservo;
Servo servo1;
Servo servo2;
#define EN 44
#define ENA 44
#define STP_1 27 // STP_1 & DIR_1 = X
#define DIR_1 26
#define STP_2 29 // STP_2 & DIR_2 = Y
#define DIR_2 28
#define STP_3 31 // STP_3 & DIR_3 = Z
#define DIR_3 30

volatile int steps1 = 0;
volatile int steps2 = 0;
volatile int steps3 = 0;
volatile bool moving = false;

unsigned long startTime;
unsigned long interval1 = 1200; // First interval duration in milliseconds
unsigned long interval2 = 4000; // Second interval duration in milliseconds

unsigned long startTime2;
unsigned long interval21 = 1200; // First interval duration in milliseconds
unsigned long interval22 = 4000; // Second interval duration in milliseconds


#define btn1 34
#define btn2 36
#define btn3 38
#define btn4 40
#define btn5 47
#define btn6 49
#define btn7 51
#define btn8 53


// Motor control pins
#define RPWM1 2
#define LPWM1 3
#define RPWM2 4
#define LPWM2 5
#define RPWM3 6
#define LPWM3 7
#define RPWM4 8
#define LPWM4 9

// Ultrasonic sensor pins
const int trigPin1 = A0;  // Trigger pin for sensor 1
const int echoPin1 = A1;  // Echo pin for sensor 1
const int trigPin2 = A2;  // Trigger pin for sensor 2
const int echoPin2 = A3;  // Echo pin for sensor 2

// Distance threshold for stopping the robot
const int stopDistance = 22;

int normalSpeed = 48;
int reducedSpeed = 32;
int spd = normalSpeed;

boolean objectDetected = false; // Variable to track if an object is detected

// Function to get distance from ultrasonic sensor
long getDistance(int trigPin, int echoPin) {
  // Send a trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pulse
  long duration = pulseIn(echoPin, HIGH, 30000L); // Timeout after 30ms

  if (duration == 0) {
    // No echo received, return a large number
    return 9999;
  }

  // Calculate the distance
  long distance = duration * 0.034 / 2;

  return distance;
}
