#include <Wire.h>

// Dirección del esclavo
#define SLAVE_ADDR 0x42
void setup() {
  // Inicializa el bus I2C como esclavo
  Wire.begin(SLAVE_ADDR);
  Wire.onRequest(sendData);
}

void loop() {

}
void sendData() {
  // Enviar un dato a través de la conexión I2C cuando se solicita
  int dataToSend = random(42);
  Wire.write(dataToSend);
