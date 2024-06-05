// STP1 false = maju , true= mundur X
// STP2 false = kiri, true = kanan  Y
// STP3 false = kiri, true = kanan  Z
void planF() {

  if (ok == 1) {

    // PLAN F

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
    eksekusi(true, false, true, 11500, 3000, 0);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    eksekusi(false, false, true, 11500, 1500, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 4    //Sampah 3
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 6000, 0, 4200);
    ambil(180, LOW, 0);
    //BUANG KE FERO
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 6000, 8000, 9000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 7    //Sampah 4
    delay(500);
    ok = 1;
    eksekusi(true, false, true, 11500, 0, 0);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    eksekusi(false, false, true, 11500, 8500, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 8    //Sampah 5
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 5700, 8500, 5600);
    ambil(180, LOW, 0);
    //BUANG KE DAUN
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 5700, 8500, 14000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 3    //Sampah 6
    delay(500);
    ok = 1;
    eksekusi(true, true, false, 11500, 0, 5800);
    ambil(180, LOW, 0);
    //BUANG KE DAUN
    delay(500);
    ok = 1;
    eksekusi(false, true, false, 11500, 5700, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 2    //Sampah 7
    delay(500);
    ok = 1;
    serv(29, 88);   // Tanpa steper
    eksekusi(false, false, false, 0, 700, 0);
    ambil(180, LOW, 0);
    // BUANG KE PLASTIK
    delay(500);
    ok = 1;
    serv(88, 29);
    eksekusi(false, true, true, 0, 3000, 5700);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 9    //Sampah 8
    delay(500);
    ok = 1;
    serv(165, 88);
    eksekusi(false, true, true, 0, 670, 7000);
    ambil(180, LOW, 0);
    //BUANG KE NON-FERO
    delay(500);
    ok = 1;
    serv(73, 168);    //Tanpa steper
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 10   //Sampah 9
    delay(500);
    ok = 1;
    serv(140, 73);
    eksekusi(false, true, true, 0, 100, 8000);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(500);
    ok = 1;
    serv(88, 140);
    eksekusi(false, false, false, 0, 7800, 7500);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 11    //Sampah 10
    delay(500);
    ok = 1;
    serv(5, 88);
    eksekusi(false, false, false, 0, 100, 12700);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    serv(88, 5);
    eksekusi(false, true, false, 0, 8100, 0);
    buang(HIGH, 100, 0);
  }
  ok = 0;

}
