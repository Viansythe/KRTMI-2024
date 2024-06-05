// STP1 false = maju , true= mundur X
// STP2 false = kiri, true = kanan  Y
// STP3 false = kiri, true = kanan  Z
void planH() {

  if (ok == 1) {

    // PLAN H
    //Ambil sampah 6    //Sampah 1
    eksekusi(true, true, true, 900, 2500, 0);
    ambil(180, LOW, 0);
    //BUANG KE FERO
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 5700, 1500, 4000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 8    //Sampah 2
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 11500, 0, 0);
    ambil(180, LOW, 0);
    //BUANG KE DAUN
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 11500, 8900, 8000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 4    //Sampah 3
    delay(300);
    ok = 1;
    eksekusi(true, false, false, 6000, 0, 0);
    ambil(180, LOW, 0);
    //BUANG KE koran
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 6000, 8300, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 5    //Sampah 4
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 11500, 2800, 0);
    ambil(180, LOW, 0);
    //BUANG KE plastik
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 11500, 1000, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 7    //Sampah 5
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 11500, 3500, 6800);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(600);
    ok = 1;
    eksekusi(false, true, true, 11500, 7500, 7000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 2    //Sampah 6
    delay(500);
    ok = 1;
    eksekusi(true, false, true, 5700, 0, 14000);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 6000, 8500, 5500);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 3    //Sampah 7
    delay(500);
    ok = 1;
    serv(29, 88);
    eksekusi(true, false, false, 0, 0, 9500);
    ambil(180, LOW, 0);
    // BUANG KE DAUN
    delay(500);
    ok = 1;
    serv(92, 29);     // TANPA STEPER
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 9    //Sampah 8
    delay(500);
    ok = 1;
    serv(5, 92);
    eksekusi(true, false, false, 0, 0, 3000);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(300);
    ok = 1;
    serv(90, 5);
    eksekusi(true, true, true, 0, 7500, 9000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 1   //Sampah 9
    delay(500);
    ok = 1;
    serv(167, 90);
    eksekusi(true, true, true, 0, 0, 3000);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    serv(88, 167);
    eksekusi(true, false, false, 0, 8000, 3300);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 10    //Sampah 10
    delay(500);
    ok = 1;
    serv(142, 88);
    eksekusi(true, true, true, 0, 8500, 10600);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    serv(88, 142);
    eksekusi(true, false, false, 0, 8000, 6800);
    buang(HIGH, 100, 0);
  }
  ok = 0;

}
