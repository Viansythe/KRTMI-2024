void maju() {
  analogWrite(ENA1, 200);
  analogWrite(ENB1, 200);
  analogWrite(ENA2, 200);
  analogWrite(ENB2, 200);

  digitalWrite(R1M1, HIGH);
  digitalWrite(R1M2, LOW);
  digitalWrite(L1M1, HIGH);
  digitalWrite(L1M2, LOW);

  digitalWrite(R2M1, HIGH);
  digitalWrite(R2M2, LOW);
  digitalWrite(L2M1, HIGH);
  digitalWrite(L2M2, LOW);

  Serial.println("PENCET ANALOG KIRI KE ATAS");
}

void mundur() {
  analogWrite(ENA1, 200);
  analogWrite(ENB1, 200);
  analogWrite(ENA2, 200);
  analogWrite(ENB2, 200);

  digitalWrite(R1M1, LOW);
  digitalWrite(R1M2, HIGH);
  digitalWrite(L1M1, LOW);
  digitalWrite(L1M2, HIGH);

  digitalWrite(R2M1, LOW);
  digitalWrite(R2M2, HIGH);
  digitalWrite(L2M1, LOW);
  digitalWrite(L2M2, HIGH);
  

  Serial.println("PENCET ANALOG KIRI KE BAWAH");
}

void kanan() {
  analogWrite(ENA1, 200);
  analogWrite(ENB1, 200);
  analogWrite(ENA2, 200);
  analogWrite(ENB2, 200);

  digitalWrite(R1M1, HIGH);
  digitalWrite(R1M2, LOW);
  digitalWrite(L1M1, LOW);
  digitalWrite(L1M2, HIGH);

  digitalWrite(R2M1, LOW);
  digitalWrite(R2M2, HIGH);
  digitalWrite(L2M1, HIGH);
  digitalWrite(L2M2, LOW);

  Serial.println("PENCET ANALOG KIRI KE KANAN");
}

void kiri() {
  analogWrite(ENA1, 200);
  analogWrite(ENB1, 200);
  analogWrite(ENA2, 200);
  analogWrite(ENB2, 200);

  digitalWrite(R1M1, LOW);
  digitalWrite(R1M2, HIGH);
  digitalWrite(L1M1, HIGH);
  digitalWrite(L1M2, LOW);

  digitalWrite(R2M1, HIGH);
  digitalWrite(R2M2, LOW);
  digitalWrite(L2M1, LOW);
  digitalWrite(L2M2, HIGH);

  Serial.println("PENCET ANALOG KIRI KE KIRI");
}

void muterkanan() {
  analogWrite(ENA1, 200);
  analogWrite(ENB1, 200);
  analogWrite(ENA2, 200);
  analogWrite(ENB2, 200);

  digitalWrite(R1M1, HIGH);
  digitalWrite(R1M2, LOW);
  digitalWrite(L1M1, HIGH);
  digitalWrite(L1M2, LOW);

  digitalWrite(R2M1, LOW);
  digitalWrite(R2M2, HIGH);
  digitalWrite(L2M1, LOW);
  digitalWrite(L2M2, HIGH);

  Serial.println("PENCET ANALOG KANAN KE KIRI");
}

void muterkiri() {
  analogWrite(ENA1, 200);
  analogWrite(ENB1, 200);
  analogWrite(ENA2, 200);
  analogWrite(ENB2, 200);

  digitalWrite(R1M1, LOW);
  digitalWrite(R1M2, HIGH);
  digitalWrite(L1M1, LOW);
  digitalWrite(L1M2, HIGH);

  digitalWrite(R2M1, HIGH);
  digitalWrite(R2M2, LOW);
  digitalWrite(L2M1, HIGH);
  digitalWrite(L2M2, LOW);

  Serial.println("PENCET ANALOG KANAN KE KIRI");
}

void turun() {
  analogWrite(ENA3, 200);
  digitalWrite(R3M1, HIGH);
  digitalWrite(R3M2, LOW);

  Serial.println("PENCET ANALOG KANAN KE ATAS");
}

void naik() {
  analogWrite(ENA3, 200);
  digitalWrite(R3M1, LOW);
  digitalWrite(R3M2, HIGH);

  Serial.println("PENCET ANALOG KANAN KE BAWAH");
}

void berhenti() {
  analogWrite(ENA1, 0);
  analogWrite(ENB1, 0);
  analogWrite(ENA2, 0);
  analogWrite(ENB2, 0);
  analogWrite(ENA3, 0);

  digitalWrite(R1M1, LOW);
  digitalWrite(R1M2, LOW);
  digitalWrite(L1M1, LOW);
  digitalWrite(L1M2, LOW);

  digitalWrite(R2M1, LOW);
  digitalWrite(R2M2, LOW);
  digitalWrite(L2M1, LOW);
  digitalWrite(L2M2, LOW);

  digitalWrite(R3M1, LOW);
  digitalWrite(R3M2, LOW);

  Serial.println("BERHETI");
}
