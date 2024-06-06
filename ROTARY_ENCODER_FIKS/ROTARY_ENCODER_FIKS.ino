// Definisikan pin untuk Rotary Encoder
const int encoderPinA = 20;
const int encoderPinB = 21;
volatile long encoderPos = 0;

void setup() {
  // Konfigurasi pin sebagai input
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);

  // Mengaktifkan internal pullup resistor
  digitalWrite(encoderPinA, HIGH);
  digitalWrite(encoderPinB, HIGH);

  // Mengaktifkan interrupt pada perubahan logika pin encoderPinA
  attachInterrupt(digitalPinToInterrupt(encoderPinA), updateEncoder, CHANGE);

  // Membuka serial komunikasi untuk debugging
  Serial.begin(115200);
}

void loop() {
  // No need for any code here, as we're displaying encoder count in updateEncoder()
}

void updateEncoder() {
  // Baca status encoderPinB
  int encoderPinBStatus = digitalRead(encoderPinB);
  
  // Periksa arah putaran
  if (digitalRead(encoderPinA) != encoderPinBStatus) {
    encoderPos++;
  } else {
    encoderPos--;
  }
  
  // Tampilkan jumlah angka yang ada saat diputar
  Serial.print("Encoder count: ");
  Serial.println(encoderPos);
}
