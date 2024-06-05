// STP1 false = maju , true= mundur X
// STP2 false = kiri, true = kanan  Y
// STP3 false = kiri, true = kanan  Z
void planC() {

  if (ok == 1) {

    // PLAN C

    //Ambil sampah 6    //Sampah 1
    eksekusi(true, true, true, 900, 2500, 0);
    ambil(180, LOW, 0);
    //BUANG KE DAUN
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 5700, 5700 , 5700);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 4    //Sampah 2
    delay(650);
    ok = 1;
    eksekusi(true, true, true, 6000, 0, 0);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 6000, 8000, 500);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 5    //Sampah 3
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 11500, 3000, 0);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 11500, 2700, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 7    //Sampah 4
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 11500, 0, 8800);
    ambil(180, LOW, 0);
    //BUANG KE NON-FERO
    delay(500);
    ok = 1;
    eksekusi(false, false, true, 11500, 4700, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 8    //Sampah 5
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 6000, 3000, 6800);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 6000, 8000, 6500);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 3    //Sampah 6
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 11500, 0, 14000);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 11500, 8000, 2500);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 1    //Sampah 7
    delay(500);
    ok = 1;
    serv(3, 88);
    eksekusi(false, false, false, 0, 8000, 200);
    ambil(180, LOW, 0);
    // BUANG KE DAUN
    delay(500);
    ok = 1;
    serv(88, 3);
    eksekusi(false, true, false, 0, 4000, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 2    //Sampah 8
    delay(500);
    ok = 1;
    serv(30, 88);
    eksekusi(false, false, false, 0, 1000, 0);
    ambil(180, LOW, 0);
    //BUANG KE FERO
    delay(500);
    ok = 1;
    serv(88, 30);
    eksekusi(true, true, true, 0, 3000, 15000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 10   //Sampah 9
    delay(500);
    ok = 1;
    serv(143, 88);
    eksekusi(true, true, true, 0, 2700, 4000);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    serv(88, 143);
    eksekusi(true, false, false, 0, 8000, 7300);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 9    //Sampah 10
    delay(500);
    ok = 1;
    serv(166, 88);
    eksekusi(true, true, false, 0, 7000, 0);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    serv(88, 166);
    eksekusi(true, false, false, 0, 6000, 5600);
    buang(HIGH, 100, 0);
  }
  ok = 0;

}
