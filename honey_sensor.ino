#include <FreqCount.h>

//Components Value in IC 555 Module
#define r1 1000             //Resistor I ; Ω
#define pot 9600000         //Potentiometer ; Ω
#define c 62E09             //Capacitor ; F
#define pl 0.3              //Cell Constant ; cm

float ec, ecf, r2, sc, scf, count;

//r2  = Parallel Value r1 + pot
//ecf = Conductivity
//scf = Sample Concentration
//count = Frequency

void setup() {
  Serial.begin(57600);
  FreqCount.begin(1000);
  Serial.print("Frequency\t");
  Serial.print("Conductivity\t");
  Serial.print("Concentration\n");
}

void loop() {
//Sample Frequency Count
  if (FreqCount.available()) {
    unsigned long count = FreqCount.read();

  Serial.print(count);
  Serial.print("Hz\t");
  Serial.print("\t");
  
//Conductivity Value
  if  (count>0) {
      r2  = (11612903.226/count) - 500;
      ec  = ((1/r2) - (1/pot))/pl;
      ecf = ec*1000000;
      
      Serial.print(ecf);
      Serial.print("μS/cm\t");
  
//Concentration Estimation
  if (ecf > 0) { 
      sc = 0.0008*ecf + 0.0152;
      scf = sc*100;

        Serial.print(scf);
        Serial.print("%\n");

  }
  }
  delay (1000);
  }
}
