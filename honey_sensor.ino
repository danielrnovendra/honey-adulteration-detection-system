//Library pembacaan Frekuensi
#include <FreqCount.h>

//Besaran komponen pada modul
#define r1 1000             //Resistor I ; Ω
#define pot 9600000         //Potensiometer ; Ω
#define c 62E09             //Kapasitor ; F
#define pl 0.3              //Cell Constant ; cm

float ec, ecf, r2, sc, scf, count;

//r2  = nilai paralel R1+Rpot
//ecf = konduktivitas
//scf = konsentrasi
//count = frekuensi

void setup() {
  Serial.begin(57600);
  FreqCount.begin(1000);
  Serial.print("Frekuensi\t");
  Serial.print("Konduktivitas\t");
  Serial.print("Konsentrasi\n");
}

void loop() {
//Pembacaan Frekuensi Sampel
  if (FreqCount.available()) {
    unsigned long count = FreqCount.read();

  Serial.print(count);
  Serial.print("Hz\t");
  Serial.print("\t");
//Pembacaan Nilai Konduktivitas
  if  (count>0) {
      r2  = (11612903.226/count) - 500;
      ec  = ((1/r2) - (1/pot))/pl;
      ecf = ec*1000000;
      
      Serial.print(ecf);
      Serial.print("μS/cm\t");
  
//Pembacaan Konsentrasi
  if (ecf > 0) { 
      sc = 0.0008*ecf + 0.0152;
      scf = sc*100;

      //if (scf<0) {
        //Serial.print("0%\n");
      //}
      //else if (scf>=0) {
        Serial.print(scf);
        Serial.print("%\n");
      //}
  }
  }
  delay (1000);
  }
}
