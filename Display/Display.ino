#include "DHT.h"
#include <TM1637Display.h>
#define DHTPIN 4
#define DHTTYPE DHT11
#define CLK 21
#define DIO 22

TM1637Display display(CLK, DIO);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  display.setBrightness(0x0f);
  dht.begin();
  display.showNumberDec(0, false);
}

void loop() {
  // Leer la temperatura
  int t = dht.readTemperature();
  // Mostrar el valor en el display
  display.showNumberDec(t, false);
  // Esperar un breve período de tiempo antes de volver a leer el valor del sensor
  delay(100);
}
