// STP1 false = maju , true= mundur X
// STP2 false = kiri, true = kanan  Y
// STP3 false = kiri, true = kanan  Z
void planB() {

  if (ok == 1) {

    // PLAN B

    //Ambil sampah 6    //Sampah 1
    eksekusi(true, true, true, 900, 2500, 0);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, false, true, 5700, 2700, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 5    //Sampah 2
    delay(500);
    ok = 1;
    eksekusi(true, false, true, 11500, 2900, 0);
    ambil(180, LOW, 0);
    //BUANG KE DAUN
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 11500, 0, 5800);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 4    //Sampah 3
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 5800, 0, 0);
    ambil(180, LOW, 0);
    //BUANG KE FERO
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 5800, 6500, 10200);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 8    //Sampah 4
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 6000, 0, 5800);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 6000, 6000, 8000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 7    //Sampah 5
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 11500, 6000, 2500);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 11500, 7000, 5600);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 3    //Sampah 6
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 11300, 0, 9800);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 11300, 6000, 3400);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 2    //Sampah 7
    delay(500);
    ok = 1;
    serv(29, 88);
    eksekusi(true, false, false, 0, 4500, 0);
    ambil(180, LOW, 0);
    // BUANG KE PLASTIK
    delay(500);
    ok = 1;
    serv(88, 29);
    eksekusi(true, true, true, 0, 6000, 3400);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 9    //Sampah 8
    delay(500);
    ok = 1;
    serv(166, 88);
    eksekusi(true, true, true, 0, 0, 6700);
    ambil(180, LOW, 0);
    //BUANG KE NON-FERO
    delay(500);
    ok = 1;
    serv(88, 166);
    eksekusi(true, false, false, 0, 2700, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 10   //Sampah 9
    delay(500);
    ok = 1;
    serv(140, 88);
    eksekusi(true, true, true, 0, 1600, 9600);
    ambil(180, LOW, 0);
    //BUANG KE DAUN
    delay(600);
    ok = 1;
    serv(88, 140);
    eksekusi(true, false, false, 0, 8000, 16000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 1    //Sampah 10
    delay(500);
    ok = 1;
    serv(4, 88);
    eksekusi(true, false, false, 0, 0, 3700);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(100);
    ok = 1;
    serv(88, 4);
    eksekusi(true, true, true, 0, 7000, 5000);
    buang(HIGH, 100, 0);
  }
  ok = 0;

}
