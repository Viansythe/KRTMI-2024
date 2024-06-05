#include "var.h"

bool allSensorsBelowThresholdForward = false; // Flag to indicate all forward sensors are below threshold
bool allSensorsBelowThresholdLeft = false; // Flag to indicate all left sensors are below threshold

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

void ControlForward() {
  // Read voltage values from photodiodes
  int diodeVoltage1 = analogRead(photoDiodePin1);
  int diodeVoltage2 = analogRead(photoDiodePin2);
  int diodeVoltage3 = analogRead(photoDiodePin3);
  int diodeVoltage4 = analogRead(photoDiodePin4);
  int diodeVoltage5 = analogRead(photoDiodePin5);
  int diodeVoltage6 = analogRead(photoDiodePin6);
  int diodeVoltage7 = analogRead(photoDiodePin7);
  int diodeVoltage8 = analogRead(photoDiodePin8);

  // Display values from each photodiode
  Serial.print("Photodiode 1: ");
  Serial.print(diodeVoltage1);
  Serial.print(", Photodiode 2: ");
  Serial.print(diodeVoltage2);
  Serial.print(", Photodiode 3: ");
  Serial.print(diodeVoltage3);
  Serial.print(", Photodiode 4: ");
  Serial.println(diodeVoltage4);
  Serial.print("Photodiode 5: ");
  Serial.print(diodeVoltage5);
  Serial.print(", Photodiode 6: ");
  Serial.print(diodeVoltage6);
  Serial.print(", Photodiode 7: ");
  Serial.print(diodeVoltage7);
  Serial.print(", Photodiode 8: ");
  Serial.println(diodeVoltage8);

  // Check if sensor values are above threshold
  bool sensor1Detected = diodeVoltage1 > threshold1;
  bool sensor2Detected = diodeVoltage2 > threshold2;
  bool sensor3Detected = diodeVoltage3 > threshold3;
  bool sensor4Detected = diodeVoltage4 > threshold4;
  bool sensor5Detected = diodeVoltage5 > threshold5;
  bool sensor6Detected = diodeVoltage6 > threshold6;
  bool sensor7Detected = diodeVoltage7 > threshold7;
  bool sensor8Detected = diodeVoltage8 > threshold8;

  // If all sensors are above threshold, move robot forward
  if (sensor1Detected && sensor2Detected && sensor3Detected && sensor4Detected &&
      sensor5Detected && sensor6Detected && sensor7Detected && sensor8Detected) {
    maju();
    Serial.println("Moving forward");
    allSensorsBelowThresholdForward = false; // Reset flag
  }
  //=========================No line 1,8===================================
  else if (!sensor1Detected && sensor2Detected && sensor3Detected && sensor4Detected &&
           sensor5Detected && sensor6Detected && sensor7Detected && !sensor8Detected) {
    luruskanan();
    Serial.println("Straightening to the left");
    allSensorsBelowThresholdForward = false; // Reset flag
  }

  //=========================No line 1,2,7,8===================================
  else if (!sensor1Detected && !sensor2Detected && sensor3Detected && sensor4Detected &&
           sensor5Detected && sensor6Detected && !sensor7Detected && !sensor8Detected) {
    luruskanan();
    Serial.println("Straightening to the left");
    allSensorsBelowThresholdForward = false; // Reset flag
  }
  //=========================No line 4,5===================================
  else if (sensor1Detected && sensor2Detected && sensor3Detected && !sensor4Detected &&
           !sensor5Detected && sensor6Detected && sensor7Detected && sensor8Detected) {
    luruskiri();
    Serial.println("Straightening to the right");
    allSensorsBelowThresholdForward = false; // Reset flag
  }

  //=========================No line 3,4,5,6===================================
  else if (sensor1Detected && sensor2Detected && !sensor3Detected && !sensor4Detected &&
           !sensor5Detected && !sensor6Detected && sensor7Detected && sensor8Detected) {
    luruskiri();
    Serial.println("Straightening to the right");
    allSensorsBelowThresholdForward = false; // Reset flag
  } else {
    mati();
    Serial.println("Stop");

    // If none of the sensors are detecting, set flag to true
    if (!sensor1Detected && !sensor2Detected && !sensor3Detected && !sensor4Detected &&
        !sensor5Detected && !sensor6Detected && !sensor7Detected && !sensor8Detected) {
      delay(1000);
      allSensorsBelowThresholdForward = true;
    }
  }
}

void ControlLeft() {
  int diodeVoltage9 = analogRead(photoDiodePin9);
  int diodeVoltage10 = analogRead(photoDiodePin10);
  int diodeVoltage11 = analogRead(photoDiodePin11);
  int diodeVoltage12 = analogRead(photoDiodePin12);

  // Display values from each photodiode
  Serial.print("Photodiode 9: ");
  Serial.print(diodeVoltage9);
  Serial.print(", Photodiode 10: ");
  Serial.print(diodeVoltage10);
  Serial.print(", Photodiode 11: ");
  Serial.print(diodeVoltage11);
  Serial.print(", Photodiode 12: ");
  Serial.println(diodeVoltage12);

  // Check if sensor values are above threshold
  bool sensor12Detected = diodeVoltage9 > threshold9;
  bool sensor11Detected = diodeVoltage10 > threshold10;
  bool sensor10Detected = diodeVoltage11 > threshold11;
  bool sensor9Detected = diodeVoltage12 > threshold12;

  // If all sensors are above threshold, move robot forward
  if (sensor9Detected && sensor10Detected && sensor11Detected && sensor12Detected) {
    maju();
    Serial.println("Moving forward");
    allSensorsBelowThresholdLeft = false; // Reset flag
  }
  //=========================No line 9 ===================================
  else if (!sensor9Detected && sensor10Detected && sensor11Detected && sensor12Detected) {
    luruskanan();
    Serial.println("Straightening to the left");
    allSensorsBelowThresholdLeft = false; // Reset flag
  }

  //=========================No line 9.10===================================
  else if (!sensor9Detected && !sensor10Detected && sensor11Detected && sensor12Detected) {
    luruskanan();
    Serial.println("Straightening to the left");
    allSensorsBelowThresholdLeft = false; // Reset flag
  }
  //=========================No line 12===================================
  else if (sensor9Detected && sensor10Detected && sensor11Detected && !sensor12Detected) {
    luruskiri();
    Serial.println("Straightening to the right");
    allSensorsBelowThresholdLeft = false; // Reset flag
  }

  //=========================No line 11,12===================================
  else if (sensor9Detected && sensor10Detected && !sensor11Detected && !sensor12Detected) {
    luruskiri();
    Serial.println("Straightening to the right");
    allSensorsBelowThresholdLeft = false; // Reset flag
  } else {
    mati();
    Serial.println("Stop");

    // If none of the sensors are detecting, set flag to true
    if (!sensor9Detected && !sensor10Detected && !sensor11Detected && !sensor12Detected) {
      delay(1000);
      allSensorsBelowThresholdLeft = true;
    }
  }
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
  analogWrite(LPWM4, spd);
  analogWrite(RPWM4, 0);
}

void mundur() {
  analogWrite(LPWM1, 0);
  analogWrite(RPWM1, spd);
  analogWrite(LPWM2, spd);
  analogWrite(RPWM2, 0);
  analogWrite(LPWM3, 0);
  analogWrite(RPWM3, spd);
  analogWrite(LPWM4, 0);
  analogWrite(RPWM4, spd);
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
  ControlForward();
  delay(100); // Tunda selama 100 milidetik sebelum membaca sensor lagi
  ControlLeft();
  delay(100);
}
