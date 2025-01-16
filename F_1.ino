void leInputRegister() {
  //Call once inside loop() - all magic here

  //
  int vet[3] = { 39, 34, 35 };
  for (int i = 0; i < 3; i++) {
    pinMode(vet[i], INPUT);
    if (digitalRead(vet[i])) bitSet(inputRegister2, i);
    else bitClear(inputRegister2, i);
  }


  if (Serial.available()) {
    number = 0;
    boolean negative = false;  // Flag para números negativos

    // Lê os bytes enquanto houver caracteres disponíveis
    while (Serial.available()) {
      char byteRead = Serial.read();  // Lê o byte da serial

      // Verifica se é um caractere de novo linha (indicando fim da entrada)
      if (byteRead == '\n' || byteRead == '\r') {
        break;
      }

      // Se o primeiro caractere for '-', o número é negativo
      if (byteRead == '-' && number == 0) {
        negative = true;
        continue;
      }

      // Verifica se o byte lido é um dígito
      if (byteRead >= '0' && byteRead <= '9') {
        number = number * 10 + (byteRead - '0');  // Converte o caractere para um número
      }
      delay(2);
    }
    inputRegister = number;
  }
}