// STP1 false = maju , true= mundur X
// STP2 false = kiri, true = kanan  Y
// STP3 false = kiri, true = kanan  Z
void planA() {

  if (ok == 1) {

    // PLAN A

    //Ambil sampah 6    //Sampah 1
    eksekusi(true, true, true, 900, 2400, 0);
    ambil(180, LOW, 0);
    //BUANG KE DAUN
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 5700, 6100, 5500);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 4    //Sampah 2
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 6000, 0, 0);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 6000, 4400, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 5    //Sampah 3
    delay(700);
    ok = 1;
    eksekusi(true, true, true, 11500, 1700, 0);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(700);
    ok = 1;
    eksekusi(false, true, true, 11500, 0, 2800);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 7    //Sampah 4
    delay(500);
    ok = 1;
    eksekusi(true, true, true, 11500, 0, 8500);
    ambil(180, LOW, 0);
    //BUANG KE FERO
    delay(500);
    ok = 1;
    eksekusi(false, true, true, 11500, 0, 0);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 8    //Sampah 5
    delay(700);
    ok = 1;
    eksekusi(true, true, true, 5700, 600, 4800);
    ambil(180, LOW, 0);
    //BUANG KE KERTAS
    delay(500);
    ok = 1;
    eksekusi(false, false, false, 5700, 7200, 11700);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 3    //Sampah 6
    delay(500);
    ok = 1;
    eksekusi(true, false, false, 11500, 0, 9600);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(600);
    ok = 1;
    eksekusi(false, true, true, 11500, 8000, 6000);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 2    //Sampah 7
    delay(500);
    ok = 1;
    serv(30, 88);
    eksekusi(true, false, false, 0, 6900, 1450);
    ambil(180, LOW, 0);
    // BUANG KE NON-FERO
    delay(500);
    ok = 1;
    serv(90, 30);
    eksekusi(false, true, true, 0, 7300, 5400);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 10    //Sampah 8
    delay(500);
    ok = 1;
    serv(143, 90);
    eksekusi(false, true, true, 0, 0, 11500);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(700);
    ok = 1;
    serv(88, 143);
    eksekusi(false, false, false, 0, 7800, 7100);
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 10   //Sampah 9
    delay(500);
    ok = 1;
    serv(165, 88);
    eksekusi(false, true, true, 0, 6900, 200);
    ambil(180, LOW, 0);
    //BUANG KE PLASTIK
    delay(700);
    ok = 1;
    serv(88, 165);
    eksekusi(false, false, false, 0, 5600, 2000); //cek fulu
    buang(HIGH, 100, 0);
    //AMBIL SAMPAH 1    //Sampah 10
    delay(500);
    ok = 1;
    serv(5, 88);
    eksekusi(false, false, false, 0, 300, 11900);
    ambil(180, LOW, 0);
    //BUANG KE DAUN
    delay(100);
    ok = 1;
    serv(88, 5);
    eksekusi(false, true, true, 0, 4050, 0);
    buang(HIGH, 100, 0);
  }
  ok = 0;

}
