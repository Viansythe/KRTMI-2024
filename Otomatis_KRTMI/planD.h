// STP1 false = maju , true= mundur X
// STP2 false = kiri, true = kanan  Y
// STP3 false = kiri, true = kanan  Z
void planD() {

  if (ok == 1) {

    // PLAN D

    //Ambil sampah 6    //Sampah 1
    eksekusi(true, true, true, 900, 2500, 0);
    ambil(180, LOW, 0);
    //BUANG KE NON-FERO
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 5700, 1500, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 7    //Sampah 2
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 11500, 0, 4000);
    ambil(180, LOW, 0);
    //BUANG KE DAUN
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 11500, 8000, 9000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 4    //Sampah 3
    delay(700);
    ok = 1;
    eksekusi(true, false, false, 6000, 0, 0);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    eksekusi(false, true, false, 6000, 4300, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 5    //Sampah 4
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 11500, 1300, 0);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 11500, 1300, 1700);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 3    //Sampah 5
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 11500, 7000, 7300);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(600);
    ok = 1;
    eksekusi(false, true, true, 11500, 7000, 7300);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 8    //Sampah 6
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 6000, 0, 14000);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 6000, 7000, 7000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 2    //Sampah 7
    delay(500);
    ok = 1;
    serv(31, 88);
    eksekusi(false, false, false, 0, 600, 9000);
    ambil(180, LOW, 0);
    // BUANG KE DAUN
    delay(500);
    ok = 1;
    serv(90, 31);//tanpa steper
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 1    //Sampah 8
    delay(500);
    ok = 1;
    serv(3, 90);
    eksekusi(false, false, false, 0, 0, 3000);
    ambil(180, LOW, 0);
    //BUANG KE FERO
    delay(500);
    ok = 1;
    serv(88, 3);
    eksekusi(false, true, true, 0, 7000, 14300);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 9   //Sampah 9
    delay(500);
    ok = 1;
    serv(141, 88);
    eksekusi(false, true, true, 0, 0, 6800);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    serv(88, 141);
    eksekusi(false, false, false, 0, 7000, 12500);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 10    //Sampah 10
    delay(500);
    ok = 1;
    serv(166, 88);
    eksekusi(true, true, true, 0, 7000, 4500);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    serv(88, 166);
    eksekusi(true, false, false, 0, 7000, 0);
    buang(HIGH, 100, 0);
  }
  ok = 0;

}
