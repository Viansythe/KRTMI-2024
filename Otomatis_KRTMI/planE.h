// STP1 false = maju , true= mundur X
// STP2 false = kiri, true = kanan  Y
// STP3 false = kiri, true = kanan  Z
void planE() {

  if (ok == 1) {

    // PLAN E

    //Ambil sampah 6    //Sampah 1
    eksekusi(true, true, true, 900, 2500, 0);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 5700, 7000, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 4    //Sampah 2
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 6000, 0, 4500);
    ambil(180, LOW, 0);
    //BUANG KE NON-FERO
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 6000, 8000, 5000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 7    //Sampah 3
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 11300, 0, 4300);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 11300, 8000, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 5    //Sampah 4
    delay(500);
    ok = 1;
    eksekusi(true, true, false, 11500, 0, 3500);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, true, false, 11500, 3000, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 3    //Sampah 5
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 11500, 3000, 11300);
    ambil(180, LOW, 0);
    //BUANG KE DAUN
    delay(500);
    ok = 1;
    eksekusi(false, true, false, 11500, 5800, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 2    //Sampah 6
    delay(500);
    ok = 1;
    serv(32, 88);
    eksekusi(false, false, false, 0, 800, 0);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    serv(88, 32);
    eksekusi(false, true, true, 0, 3000, 6000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 8    //Sampah 7
    delay(500);
    ok = 1;
    eksekusi(true, false, true, 6000, 0, 14300);
    ambil(180, LOW, 0);
    // BUANG KE DAUN
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 6000, 8000, 14000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 1    //Sampah 8
    delay(500);
    ok = 1;
    serv(5, 88);
    eksekusi(false, false, false, 0, 0, 4500);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    serv(88, 5);
    eksekusi(false, true, true, 0, 8000, 4700);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 9   //Sampah 9
    delay(500);
    ok = 1;
    serv(167, 88);
    eksekusi(false, true, true, 0, 0, 7000);
    ambil(180, LOW, 0);
    //BUANG KE FERO
    delay(500);
    ok = 1;
    serv(93, 167);    //Tanpa steper
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 10    //Sampah 10
    delay(500);
    ok = 1;
    serv(141, 93);
    eksekusi(false, true, true, 0, 0, 8200);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    serv(88, 143);
    eksekusi(false, false, false, 0, 8000, 11500);
    buang(HIGH, 100, 0);
  }
  ok = 0;

}
