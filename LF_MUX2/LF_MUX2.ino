#include "var.h"
#include "Photodiode.h"


void setup() {
  // Set pin sebagai output
  pinMode(RPWM1, OUTPUT);
  pinMode(LPWM1, OUTPUT);
  pinMode(RPWM2, OUTPUT);
  pinMode(LPWM2, OUTPUT);
  pinMode(RPWM3, OUTPUT);
  pinMode(LPWM3, OUTPUT);
  pinMode(RPWM4, OUTPUT);
  pinMode(LPWM4, OUTPUT);

  // Set multiplexer control pins as outputs
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);

  // Membuka serial komunikasi untuk debugging
  Serial.begin(115200);
}

int readMux(int channel) {
  // Select the correct channel based on the group of sensors
  if (channel >= 0 && channel <= 3) {
    digitalWrite(s0, LOW);
    digitalWrite(s1, LOW);
    digitalWrite(s2, LOW);
  } else if (channel >= 4 && channel <= 7) {
    digitalWrite(s0, HIGH);
    digitalWrite(s1, LOW);
    digitalWrite(s2, LOW);
  } else if (channel >= 8 && channel <= 11) {
    digitalWrite(s0, LOW);
    digitalWrite(s1, HIGH);
    digitalWrite(s2, LOW);
  } else {
    // Handle invalid channel
    return -1;
  }

  // Read the value from the sensor
  return analogRead(sigPin);
}

void controlRobotMaju() {
  int sensor1Values[4];
  int sensor3Values[4];

  // Read sensor 1 (C0 to C3)
  for (int i = 0; i < 4; i++) {
    sensor1Values[i] = readMux(i);
  }

  // Read sensor 3 (C8 to C11)
  for (int i = 8; i < 12; i++) {
    sensor3Values[i - 8] = readMux(i);
  }

  // Print sensor values for debugging
  Serial.print("Sensor 1: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(sensor1Values[i]);
    Serial.print(" ");
  }
  Serial.println();

  Serial.print("Sensor 3: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(sensor3Values[i]);
    Serial.print(" ");
  }
  Serial.println();

  // Process sensor values to determine motor actions
  int threshold = 50; // Adjust based on your sensor
  bool lineDetected1 = false, lineDetected3 = false;

  // Check if any sensor in each group detects the line
  for (int i = 0; i < 4; i++) {
    if (sensor1Values[i] > threshold) lineDetected1 = true;
    if (sensor3Values[i] > threshold) lineDetected3 = true;
  }

  if (lineDetected1 && lineDetected3) {
    maju();
    Serial.println("maju");
  } else if (sensor1Values[0] > threshold && sensor3Values[0] > threshold &&
             sensor1Values[1] > threshold && sensor3Values[1] > threshold &&
             sensor1Values[2] > threshold && sensor3Values[2] > threshold &&
             sensor1Values[3] < threshold && sensor3Values[3] < threshold) {
    kiri();
    Serial.println("lurus kiri");
  } else if (sensor1Values[0] > threshold && sensor3Values[0] > threshold &&
             sensor1Values[1] > threshold && sensor3Values[1] > threshold &&
             sensor1Values[2] < threshold && sensor3Values[2] < threshold &&
             sensor1Values[3] < threshold && sensor3Values[3] < threshold) {
    kiri();
    Serial.println("lurus kiri");
  } else if (sensor1Values[0] > threshold && sensor3Values[0] > threshold &&
             sensor1Values[1] > threshold && sensor3Values[1] < threshold &&
             sensor1Values[2] < threshold && sensor3Values[2] < threshold &&
             sensor1Values[3] < threshold && sensor3Values[3] < threshold) {
    kiri();
    Serial.println("lurus kiri");
  } else if (sensor1Values[0] < threshold && sensor3Values[0] < threshold &&
             sensor1Values[1] > threshold && sensor3Values[1] > threshold &&
             sensor1Values[2] > threshold && sensor3Values[2] > threshold &&
             sensor1Values[3] > threshold && sensor3Values[3] > threshold) {
    kanan();
    Serial.println("lurus kanan");
  } else if (sensor1Values[0] < threshold && sensor3Values[0] < threshold &&
             sensor1Values[1] < threshold && sensor3Values[1] < threshold &&
             sensor1Values[2] > threshold && sensor3Values[2] > threshold &&
             sensor1Values[3] > threshold && sensor3Values[3] > threshold) {
    kanan();
    Serial.println("lurus kanan");
  } else if (sensor1Values[0] < threshold && sensor3Values[0] < threshold &&
             sensor1Values[1] < threshold && sensor3Values[1] < threshold &&
             sensor1Values[2] < threshold && sensor3Values[2] < threshold &&
             sensor1Values[3] > threshold && sensor3Values[3] > threshold) {
    kanan();
    Serial.println("lurus kanan");
  } else {
    mati();
    delay(100);
  }

  delay(100); // Small delay for stability
}

void controlRobotKiri() {
  int sensor2Values[4];

  // Read sensor 2 (C4 to C7)
  for (int i = 4; i < 8; i++) {
    sensor2Values[i - 4] = readMux(i);
  }

  Serial.print("Sensor 2: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(sensor2Values[i]);
    Serial.print(" ");
  }
  Serial.println();

  int threshold = 50; // Adjust based on your sensor
  bool lineDetected2 = false;

  // Check if any sensor in each group detects the line
  for (int i = 0; i < 4; i++) {
    if (sensor2Values[i] > threshold) lineDetected2 = true;
  }

  if (lineDetected2) {
    maju();
    Serial.println("maju");
  } else if (sensor2Values[0] > threshold && sensor2Values[1] > threshold &&
             sensor2Values[2] > threshold && sensor2Values[3] < threshold) {
    kiri();
    Serial.println("lurus kiri");
  } else if (sensor2Values[0] > threshold && sensor2Values[1] > threshold &&
             sensor2Values[2] < threshold && sensor2Values[3] < threshold) {
    kiri();
    Serial.println("lurus kiri");
  } else if (sensor2Values[0] > threshold && sensor2Values[1] < threshold &&
             sensor2Values[2] < threshold && sensor2Values[3] < threshold) {
    kiri();
    Serial.println("lurus kiri");
  } else if (sensor2Values[0] < threshold && sensor2Values[1] > threshold &&
             sensor2Values[2] > threshold && sensor2Values[3] > threshold) {
    kanan();
    Serial.println("lurus kanan");
  } else if (sensor2Values[0] < threshold && sensor2Values[1] < threshold &&
             sensor2Values[2] > threshold && sensor2Values[3] > threshold) {
    kanan();
    Serial.println("lurus kanan");
  } else if (sensor2Values[0] < threshold && sensor2Values[1] < threshold &&
             sensor2Values[2] < threshold && sensor2Values[3] > threshold) {
    kanan();
    Serial.println("lurus kanan");
  } else {
    mati();
    delay(100);
  }
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
void maju() {
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
void kanan() {
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


void loop() {
controlRobotMaju;
delay(1000);
controlRobotKiri;
delay(1000);

}
