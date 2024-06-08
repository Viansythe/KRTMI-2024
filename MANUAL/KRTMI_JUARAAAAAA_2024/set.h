void notify() {
  //-------------------------     CEK BATTERY     ------------------------------
  if( battery != Ps3.data.status.battery ){
        battery = Ps3.data.status.battery;
        Serial.print("The controller battery is ");
        if( battery == ps3_status_battery_charging )      Serial.println("charging");
        else if( battery == ps3_status_battery_full )     Serial.println("FULL");
        else if( battery == ps3_status_battery_high )     Serial.println("HIGH");
        else if( battery == ps3_status_battery_low)       Serial.println("LOW");
        else if( battery == ps3_status_battery_dying )    Serial.println("DYING");
        else if( battery == ps3_status_battery_shutdown ) Serial.println("SHUTDOWN");
        else Serial.println("UNDEFINED");
    }


  

  //-------------------------     BUTTON CENTER     ------------------------------
  if ( Ps3.data.button.start )
  {
    s1.write(140);
    s2.write(50);
    Serial.println("START");
  }

  if ( Ps3.data.button.select )
  {
    Serial.println("SELECT");
  }

  if ( Ps3.data.button.ps )
  {
    Serial.println("PS");
  }


  //-------------------------     BUTTON RIGHT     ------------------------------
  if (Ps3.data.button.triangle) {
    sp = 255;
    Serial.println("SEGITIGA");
  }
  if ( Ps3.data.button.cross) {
    sp = 150;
    Serial.println("SILANG");
  }
  if (Ps3.data.button.circle) {
    Serial.println("LINGKARAN");
  }
  if ( Ps3.data.button.square) {
    Serial.println("KOTAK");
  }


  //-------------------------     BUTTON LEFT     ------------------------------
  if ( Ps3.data.button.up )
  {
    //Serial.println("DOWN");
  }

  if ( Ps3.data.button.down )
  {
    //Serial.println("DOWN");
  }

  if ( Ps3.data.button.left )
  {
    //Serial.println("LEFT");
  }

  if ( Ps3.data.button.right )
  {
    //Serial.println("RIGHT");
  }

  //-------------------------     BUTTON L/R     ------------------------------
  if ( Ps3.data.button.l2 ) {
    angle1 = min(angle1 - 1, 180);
    s1.write(angle1);
    delay(1);
    Serial.println("L2");//putar kanan
  }
  if ( Ps3.data.button.l1 ) {
    angle1 = max(angle1 + 1, 0);
    s1.write(angle1);
    delay(1);
    Serial.println("L1");//putar kiri
  }
  
  if ( Ps3.data.button.r2 ) {
    angle2 = min(angle2 - 1, 180);
    s2.write(angle2);
    delay(1);
    Serial.println("R2");//tutup
  }
  if ( Ps3.data.button.r1 ) {
    angle2 = max(angle2 + 1, 0);
    s2.write(angle2);
    delay(1);
    Serial.println("R1");//buka
  }
  if ( Ps3.data.button.l3 )
  {
    //Serial.println("L3");
  }
  if ( Ps3.data.button.r3 )
  {
    //Serial.println("R3");
  }

  


  //-------------------------     ANALOG     ------------------------------
  leftX = (Ps3.data.analog.stick.lx);
  leftY = (Ps3.data.analog.stick.ly);
  rightX = (Ps3.data.analog.stick.rx);
  rightY = (Ps3.data.analog.stick.ry);

  if ((leftY < -64) && (leftX >= -64) && (leftX <= 64)) {
    maju();
  }
  
  else if ((leftY > 64) && (leftX >= -64) && (leftX <= 64)) {
    mundur();
  }

  else if ((leftX > 64) && (leftY >= -64) && (leftY <= 64)) {
    kanan();
  }

  else if ((leftX < -64) && (leftY >= -64) && (leftY <= 64)) {
    kiri();
  }


  else if ((rightY < -64) && (rightX >= -64) && (rightX <= 64)) {
    naik();
  }

  else if ((rightY > 64) && (rightX >= -64) && (rightX <= 64)) {
    turun();
  }

  else if ((rightX > 64) && (rightY >= -64) && (rightY <= 64)) {
    muterkanan();
  }

  else if ((rightX < -64) && (rightY >= -64) && (rightY <= 64)) {
    muterkiri();
  }

  else {
    berhenti();
  }
}
