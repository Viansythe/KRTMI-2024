//definisikan pin photodioda
int photoDiodePin1 = A0;
int photoDiodePin2 = A1;
int photoDiodePin3 = A2;
int photoDiodePin4 = A3;
//int photoDiodePin5 = A4;
//int photoDiodePin6 = A5;  

void setup() {
  //atur pin photodioda sebagai input
  pinMode(photoDiodePin1, INPUT);
  pinMode(photoDiodePin2, INPUT);
  pinMode(photoDiodePin3, INPUT);
  pinMode(photoDiodePin4, INPUT);
//  pinMode(photoDiodePin5, INPUT);
//  pinMode(photoDiodePin6, INPUT);
  
  //buka komunikasi serial
  Serial.begin(9600);
}

void loop() {
  //baca nilai tegangan dari photodioda
  int diodeVoltage1 = analogRead(photoDiodePin1);
  int diodeVoltage2 = analogRead(photoDiodePin2);
  int diodeVoltage3 = analogRead(photoDiodePin3);
  int diodeVoltage4 = analogRead(photoDiodePin4);
//  int diodeVoltage5 = analogRead(photoDiodePin5);
//  int diodeVoltage6 = analogRead(photoDiodePin6);
  
  //konversi nilai tegangan menjadi nilai cahaya (0-1023)
  //int lightLevel = map(diodeVoltage, 0, 1023, 0, 100);
  
  //tampilkan nilai cahaya
  //Serial.print("Nilai Cahaya: ");
  Serial.print("sensor 1 : ");
  Serial.println(diodeVoltage1);
  Serial.print("sensor 2 : ");
  Serial.println(diodeVoltage2);
  Serial.print("sensor 3 : ");
  Serial.println(diodeVoltage3);
  Serial.print("sensor 4 : ");
  Serial.println(diodeVoltage4);
//  Serial.print("sensor 5 : ");
//  Serial.println(diodeVoltage5);
//  Serial.print("sensor 6 : ");
//  Serial.println(diodeVoltage6);

  //tampilkan satuan 
  //
  
  //jeda sebelum membaca nilai berikutnya
  delay(1000);
}
