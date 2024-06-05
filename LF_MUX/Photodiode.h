int readMux(int channel) {
  // Select the correct channel
  digitalWrite(s0, bitRead(channel, 0));
  digitalWrite(s1, bitRead(channel, 1));
  digitalWrite(s2, bitRead(channel, 2));
  digitalWrite(s3, bitRead(channel, 3));

  // Read the value from the sensor
  return analogRead(sensorInput);
}

void controlRobotMaju() {
  int sensor1Values[4];
  //  int sensor2Values[4];
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
  for (int i = 0; i < 4; i++) {
    Serial.print(sensor1Values[i]);
    Serial.print(" ");
    Serial.print("Sensor 1: ");
  }
  for (int i = 0; i < 4; i++) {
    Serial.print(sensor3Values[i]);
    Serial.print(" ");
    Serial.print("Sensor 3: ");
  }
  Serial.println();

  // Process sensor values to determine motor actions
  int threshold = 500; // Adjust based on your sensor
  bool lineDetected1 = false, lineDetected3 = false;

  // Check if any sensor in each group detects the line
  for (int i = 0; i < 4; i++) {
    if (sensor1Values[i] > threshold) lineDetected1 = true;
    if (sensor3Values[i] > threshold) lineDetected3 = true;
  }

  if ((lineDetected1 && lineDetected3) {
  maju();
    Serial.println("maju");
    delay(100);
  }
  else if (sensor1Values[0] && sensor3Values[0] > threshold && sensor1Values[1] && sensor3Values[1] > threshold && sensor1Values[2] && sensor3Values[2] > threshold && sensor1Values[3] && sensor3Values[3] < threshold  ) {
  kiri();
    Serial.println("lurus kiri");
    delay(100);
  }
  else if (sensor1Values[0] && sensor3Values[0] > threshold && sensor1Values[1] && sensor3Values[1] > threshold && sensor1Values[2] && sensor3Values[2] < threshold && sensor1Values[3] && sensor3Values[3] < threshold  ) {
  kiri();
    Serial.println("lurus kiri");
    delay(100);
  }
  else if (sensor1Values[0] && sensor3Values[0] > threshold && sensor1Values[1] && sensor3Values[1] < threshold && sensor1Values[2] && sensor3Values[2] < threshold && sensor1Values[3] && sensor3Values[3] < threshold  ) {
  kiri();
    Serial.println("lurus kiri");
    delay(100);
  }
  else if (sensor1Values[0] && sensor3Values[0] < threshold && sensor1Values[1] && sensor1Values[1] > threshold && sensor1Values[2] && sensor1Values[2] > threshold && sensor1Values[3] && sensor3Values[3] > threshold  ) {
  kanan();
    Serial.println("lurus kanan");
    delay(100);
  }
  else if (sensor1Values[0] && sensor3Values[0] < threshold && sensor1Values[1] && sensor1Values[1] < threshold && sensor1Values[2] && sensor1Values[2] > threshold && sensor1Values[3] && sensor3Values[3] > threshold  ) {
  kanan();
    Serial.println("lurus kanan");
    delay(100);
  }
  else if (sensor1Values[0] && sensor3Values[0] < threshold && sensor1Values[1] && sensor1Values[1] < threshold && sensor1Values[2] && sensor1Values[2] < threshold && sensor1Values[3] && sensor3Values[3] > threshold  ) {
  kanan();
    Serial.println("lurus kanan");
    delay(100);
  }
  else() {
    mati();
    delay(100);
  }
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


  int threshold = 500; // Adjust based on your sensor
 bool lineDetected2 = false;

  // Check if any sensor in each group detects the line
  for (int i = 0; i < 4; i++) {
    if (sensor2Values[i] > threshold) lineDetected2 = true;
 }

  if ((lineDetected2) {
  maju();
    Serial.println("maju");
    delay(100);
  }
  else if (sensor2Values[0] > threshold && sensor2Values[1] > threshold && sensor2Values[2] > threshold && sensor2Values[3] < threshold  ) {
  kiri();
    Serial.println("lurus kiri");
    delay(100);
  }
  else if (sensor2Values[0] > threshold && sensor2Values[1] > threshold && sensor2Values[2] < threshold && sensor2Values[3] < threshold  ) {
  kiri();
    Serial.println("lurus kiri");
    delay(100);
  }
  else if (sensor2Values[0] > threshold && sensor2Values[1] < threshold &&  sensor2Values[2] < threshold && sensor2Values[3] < threshold  ) {
  kiri();
    Serial.println("lurus kiri");
    delay(100);
  }
  else if (sensor2Values[0] < threshold &&  sensor2Values[1] > threshold && sensor2Values[2] > threshold && sensor2Values[3] > threshold  ) {
  kanan();
    Serial.println("lurus kanan");
    delay(100);
  }
  else if (sensor2Values[0] < threshold &&  sensor2Values[1] < threshold &&  sensor2Values[2] > threshold && sensor2Values[3] > threshold  ) {
  kanan();
    Serial.println("lurus kanan");
    delay(100);
  }
  else if (sensor2Values[0] < threshold && sensor2Values[1] < threshold && sensor2Values[2] < threshold && sensor2Values[3] > threshold  ) {
  kanan();
    Serial.println("lurus kanan");
    delay(100);
  }
  else() {
    mati();
    delay(100);
  }
}
