#include <ESP32Servo.h>
#include <Ps3Controller.h>
#include "var.h"
#include "voidmotor.h"
#include "set.h"



void onConnect() {
  Serial.println("Connected.");
}

void setup() {
  Serial.begin(115200);
  Ps3.attach(notify);
  Ps3.attachOnConnect(onConnect);
  Ps3.begin();

  pinMode(ENA1, OUTPUT);
  pinMode(ENB1, OUTPUT);
  pinMode(R1M1, OUTPUT);
  pinMode(R1M2, OUTPUT);
  pinMode(L1M1, OUTPUT);
  pinMode(L1M2, OUTPUT);

  pinMode(ENA2, OUTPUT);
  pinMode(ENB2, OUTPUT);
  pinMode(R2M1, OUTPUT);
  pinMode(R2M2, OUTPUT);
  pinMode(L2M1, OUTPUT);
  pinMode(L2M2, OUTPUT);

  pinMode(ENA3, OUTPUT);
  pinMode(R3M1, OUTPUT);
  pinMode(R3M2, OUTPUT);

//  pinMode(RST, INPUT_PULLUP);

  s1.attach(32);
  s2.attach(16);
  s3.attach(16);

  s1.write(0);
  s2.write(0);
  s3.write(0);


  // Set channel Parameters for each motor
  ledcSetup(motorAChannel, motorFreq, motorResolution);
  ledcSetup(motorBChannel, motorFreq, motorResolution);
  ledcSetup(motorCChannel, motorFreq, motorResolution);
  ledcSetup(motorDChannel, motorFreq, motorResolution);
  ledcSetup(motorEChannel, motorFreq, motorResolution);

  // Attach Motor PWM pins to corresponding channels
  ledcAttachPin(ENA1, motorAChannel);
  ledcAttachPin(ENB1, motorBChannel);
  ledcAttachPin(ENA2, motorCChannel);
  ledcAttachPin(ENB2, motorDChannel);
  ledcAttachPin(ENA3, motorDChannel);

  // Print to Serial Monitor
  Serial.println("Ready.");

//  a = 0;

}

void loop() {
//  int btn = digitalRead(RST);
//  //  if (btn == LOW) {
//  //    analogWrite(ENA3, sp);
//  //    digitalWrite(R3M1, HIGH);
//  //    digitalWrite(R3M2, LOW);
//  //    Serial.println("p");
//  //    delay(500);
//  //  }
//  //  else {
//  //    berhenti();
//  //  }
//  if (a == 0) {
//    if (btn == LOW) {
//      analogWrite(ENA3, sp);
//      digitalWrite(R3M1, HIGH);
//      digitalWrite(R3M2, LOW);
//      Serial.println("p");
//      a++;
//    }
//    if (a == 3) {
//      analogWrite(ENA3, sp);
//      digitalWrite(R3M1, LOW);
//      digitalWrite(R3M2, LOW);
//      Serial.println("p");
//      a = 0;
//    }
//  }
}
