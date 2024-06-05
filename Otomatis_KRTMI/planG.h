// STP1 false = maju , true= mundur X
// STP2 false = kiri, true = kanan  Y
// STP3 false = kiri, true = kanan  Z
void planG() {

  if (ok == 1) {

    // PLAN G

    //Ambil sampah 6    //Sampah 1
    eksekusi(true, true, true, 900, 2500, 0);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 5700, 2500, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 4    //Sampah 2
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 5800, 4000, 4700);
    ambil(180, LOW, 0);
    //BUANG KE DAUN
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 5800, 0, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 5    //Sampah 3
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 11500, 5500, 0);
    ambil(180, LOW, 0);
    //BUANG KE NON-FERO
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 11500, 2000, 5200);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 8    //Sampah 4
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 6000, 0, 10000);
    ambil(180, LOW, 0);
    //BUANG KE FERO
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 6000, 5500, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 7    //Sampah 5
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 11500, 0, 0);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(600);
    ok = 1;
    eksekusi(false, false, false, 11500, 2500, 10500);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 3    //Sampah 6
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 11200, 0, 10000);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 11200, 7000, 7000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 2    //Sampah 7
    delay(500);
    ok = 1;
    serv(30, 88);
    eksekusi(false, false, false, 0, 7000, 2000);
    ambil(180, LOW, 0);
    // BUANG KE PLASTIK
    delay(500);
    ok = 1;
    serv(88, 30);
    eksekusi(false, true, true, 0, 7000, 1800);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 1    //Sampah 8
    delay(500);
    ok = 1;
    serv(4, 88);
    eksekusi(false, false, false, 0, 7000, 5300);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(600);
    ok = 1;
    serv(88, 4);
    eksekusi(false, true, true, 0, 8000, 800);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 9   //Sampah 9
    delay(500);
    ok = 1;
    serv(166, 88);
    eksekusi(false, true, true, 0, 800, 10000);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    serv(88, 166);
    eksekusi(false, false, false, 0, 6800, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 10    //Sampah 10
    delay(500);
    ok = 1;
    serv(142, 88);
    eksekusi(false, true, true, 0, 6000, 9000);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    serv(88, 144);
    eksekusi(false, false, false, 0, 8500, 6500);
    buang(HIGH, 100, 0);
  }
  ok = 0;

}
