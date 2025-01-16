#include <Crescer.h>

Tempora temp1;

void leHoldingRegister() {

  temp1.defiSP(500);

  if (temp1.Saida(1)) {

    Serial.print(holdingRegister2, BIN);
    Serial.print(" - ");
    Serial.println(holdingRegister);
    temp1.Saida(0);
  }
}