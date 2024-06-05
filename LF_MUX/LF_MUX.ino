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

void loop() {
controlRobotMaju;
delay(1000);
controlRobotKiri;
delay(1000);

}

void maju() {
    // Set kecepatan motor dengan kompensasi beban roda saat maju
    analogWrite(LPWM1, spd);
    analogWrite(RPWM1, 0);
    analogWrite(LPWM2, spd);
    analogWrite(RPWM2, 0);
    analogWrite(LPWM3, 0);
    analogWrite(RPWM3, spd);
    analogWrite(LPWM4, 0);
    analogWrite(RPWM4, spd);
}

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

void kiri() {
    analogWrite(LPWM1, 0);
    analogWrite(RPWM1, spd);

    analogWrite(LPWM2, 0);
    analogWrite(RPWM2, spd);

    analogWrite(LPWM3, spd);
    analogWrite(RPWM3, 0);

    analogWrite(LPWM4, spd);
    analogWrite(RPWM4, 0);
}

void mati() {
    // Matikan motor
    analogWrite(LPWM1, 0);
    analogWrite(RPWM1, 0);
    analogWrite(LPWM2, 0);
    analogWrite(RPWM2, 0);
    analogWrite(LPWM3, 0);
    analogWrite(RPWM3, 0);
    analogWrite(LPWM4, 0);
    analogWrite(RPWM4, 0);
}
