#include "Matrice.h"
#include <ArduinoSTL.h>


void setup() {
  Serial.begin(9600);
  Matrice A = Matrice(std::vector<std::vector<double>>
                        {{1,0},
                        {0,1}});
  A.print();
}

void loop() {

}