#include <Wire.h>
#include "ADXL345.h"
#include "Adafruit_BMP085.h"

ADXL345 acel = ADXL345();
Adafruit_BMP085 bmp;

struct Eixo{
  int acelX, acelY, acelZ;
  //int giroX, giroY, giroZ;
};

Eixo eixos;
float altitude;

void setup() {
  Serial.begin(9600);
  acel.powerOn();
  if (!bmp.begin()) {
    Serial.println("Não foi possível encontrar um sensor BMP085 válido.Por favor, verifique.");
    while (1) {}
  }
}

void enviarEixos(){
  int tam = sizeof(eixos);
  char buff[tam];
  
  memcpy(&buff, &eixos, tam);
  
  Serial.write('I');
  Serial.write((uint8_t*)&buff, tam);
  Serial.write('F');
}

void enviarAltitude(){
  
  int tam = sizeof(altitude);
  char buff[tam];

  memcpy(&buff, &altitude, tam);

  Serial.write("A");
  Serial.write((uint8_t*)&buff, tam);
  Serial.write("AT");
}

void loop() {
  acel.readAccel(&eixos.acelX,&eixos.acelY,&eixos.acelZ);

  altitude = bmp.readAltitude();
  
  enviarEixos();
  enviarAltitude();

  delay(50);
}
