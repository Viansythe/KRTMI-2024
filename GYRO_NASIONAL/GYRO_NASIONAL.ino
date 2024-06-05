#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// Timers
unsigned long timer = 0;
float timeStep = 0.01;

// Pitch, Roll and Yaw values
float pitch = 0;
float roll = 0;
float yaw = 0;

// Motor pins
#define motor1R_pwm 9
#define motor1L_pwm 8
#define motor2R_pwm 7
#define motor2L_pwm 6
#define motor3R_pwm 5
#define motor3L_pwm 4
#define motor4R_pwm 3
#define motor4L_pwm 2

double Kp1 = 2;  // Proportional constant for input 1
double Ki1 = 0.01; // Integral constant for input 1
double Kd1 = 0.2; // Derivative constant for input 1

double error1 = 0;
double setpoint1 = 0; // Set target yaw to 0 (straight)
double lastError1 = 0;
double integral1 = 0;
double derivative1 = 0;
double output1 = 0;

bool calibrated = false; // Flag to indicate if the gyro is calibrated
float yaw_offset = 0;

void setup() {
  Serial.begin(115200);

  // Initialize MPU6050
  while (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }

  // Calibrate gyroscope. The calibration must be at rest.
  mpu.calibrateGyro();

  // Set threshold sensitivity. Default 3.
  mpu.setThreshold(1);
  
  pinMode(motor1R_pwm, OUTPUT);
  pinMode(motor1L_pwm, OUTPUT);
  pinMode(motor2R_pwm, OUTPUT);
  pinMode(motor2L_pwm, OUTPUT);
  pinMode(motor3R_pwm, OUTPUT);
  pinMode(motor3L_pwm, OUTPUT);
  pinMode(motor4R_pwm, OUTPUT);
  pinMode(motor4L_pwm, OUTPUT);

  // Calibrate yaw offset
  calibrateYaw();
}

void loop() {
  // Get yaw value
  getYaw();

  // Print yaw value as integer
  Serial.print("Yaw: ");
  Serial.println((int)yaw);

  // Calculate PID output
  output1 = calculatePID(yaw, setpoint1, Kp1, Ki1, Kd1, lastError1, integral1, output1);

  // Adjust motor speeds based on PID output
  adjustMotorSpeeds(output1);
}

void adjustMotorSpeeds(double pidOutput) {
  int motorSpeed = 150; // Set base motor speed
  int correction = abs(pidOutput); // Use absolute value of PID output for correction
  
  if (pidOutput > 0) { // Turn left
    analogWrite(motor1R_pwm, motorSpeed + correction);
    analogWrite(motor1L_pwm, motorSpeed - correction);
    analogWrite(motor2R_pwm, motorSpeed + correction);
    analogWrite(motor2L_pwm, motorSpeed - correction);
    analogWrite(motor3R_pwm, motorSpeed - correction);
    analogWrite(motor3L_pwm, motorSpeed + correction);
    analogWrite(motor4R_pwm, motorSpeed - correction);
    analogWrite(motor4L_pwm, motorSpeed + correction);
  } else { // Turn right
    analogWrite(motor1R_pwm, motorSpeed - correction);
    analogWrite(motor1L_pwm, motorSpeed + correction);
    analogWrite(motor2R_pwm, motorSpeed - correction);
    analogWrite(motor2L_pwm, motorSpeed + correction);
    analogWrite(motor3R_pwm, motorSpeed + correction);
    analogWrite(motor3L_pwm, motorSpeed - correction);
    analogWrite(motor4R_pwm, motorSpeed + correction);
    analogWrite(motor4L_pwm, motorSpeed - correction);
  }
}

void getYaw() {
  timer = millis();

  // Read normalized values
  Vector norm = mpu.readNormalizeGyro();

  // Calculate Yaw
  yaw = fmod(yaw + norm.ZAxis * timeStep, 360);

  // Compensate for yaw offset
  if (calibrated) {
    yaw -= yaw_offset;
  }

  // Wait for the full timeStep period
  delay((timeStep * 1000) - (millis() - timer));
}

double calculatePID(double input, double setpoint, double Kp, double Ki, double Kd, double &lastError, double &integral, double &output) {
  double error = setpoint - input;
  integral += error;
  
  double derivative = error - lastError;
  
  output = Kp * error + Ki * integral + Kd * derivative;
  
  lastError = error;  
  return output;
}

void calibrateYaw() {
  Serial.println("Calibrating yaw offset...");
  delay(5000); // Wait for the gyro to stabilize

  // Read the initial yaw value
  Vector norm = mpu.readNormalizeGyro();
  yaw_offset = fmod(norm.ZAxis, 360);

  Serial.print("Yaw offset: ");
  Serial.println(yaw_offset);

  calibrated = true;
}
