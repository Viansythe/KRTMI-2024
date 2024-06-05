void step (boolean dir, byte dirPin, byte stepperPin, volatile int& steps)
{
  digitalWrite (dirPin, dir);
  steps = 0;
  moving = true;
  startTime = millis(); // Record the start time when stepping starts
}

void adjustTimer3Interval() {
  unsigned long elapsedTime = millis() - startTime;
  if (elapsedTime < interval1) {
    Timer1.initialize(370);
  }
  else if (elapsedTime < interval2) {
    Timer1.initialize(260);
  }
  else {
    Timer1.initialize(220); // Default or final speed
  }
  if (steps3 < 2000) {
    Timer1.initialize(350);
  }
  else if (steps3 < 1000) {
    Timer1.initialize(600);
  }
  else if (steps3 < 2500) {
    Timer1.initialize(300);
  }
}

void adjustTimer2Interval() {
  unsigned long elapsedTime2 = millis() - startTime2;
  if (elapsedTime2 < interval21) {
    Timer1.initialize(300);}
  else {
    Timer1.initialize(260); // Default or final speed
  }  if (steps2 < 500) {
    Timer1.initialize(280);
  }
}



void timerIsr() {
  if (moving) {
    if (steps1 > 0) {
      digitalWrite(STP_1, !digitalRead(STP_1));
      steps1--;
      Timer1.initialize(80);
    }
    if (steps2 > 0) {
      digitalWrite(STP_2, !digitalRead(STP_2));
      steps2--;
      adjustTimer2Interval();
    }
    if (steps3 > 0) {
      digitalWrite(STP_3, !digitalRead(STP_3));
      steps3--;
      adjustTimer3Interval();
    }
    if (steps1 == 0 && steps2 == 0 && steps3 == 0) {
      moving = false;
    }
  }
}

void serv(int k, int a) {
  if (a <= k) {
    for (i = a; i <= k; i++) {
      servo1.write(i);
      servo2.write(i);
      delay(25);
    }
  }
  else {
    for (i = a; i >= k; i--) {
      servo1.write(i);
      servo2.write(i);
      delay(25);
    }
  }
}

void eksekusi(bool TF_A, bool TF_B, bool TF_C, int nA, int nB, int nC) {
  if (ok == 1) {
    step(TF_A, DIR_1, STP_1, steps1);
    steps1 = nA * 2;
    step(TF_B, DIR_2, STP_2, steps2);
    steps2 = nB * 2;
    step(TF_C, DIR_3, STP_3, steps3);
    steps3 = nC * 2;
    while (moving) delay(1);
    delay(500);
  }
  ok = 0;
}

void ambil(int srv, bool rly, int srv1) {
  myservo.write(srv);
  delay(600);
  digitalWrite(relayPin, rly);
  delay(700);
  myservo.write(srv1);
}

void buang(bool rly, int srv, int srv1) {
  digitalWrite(relayPin, rly);
  delay(700);
  myservo.write(srv);
  delay(700);
  myservo.write(srv1);
}
