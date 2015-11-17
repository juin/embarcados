#include <Wire.h>
#include "ADXL345.h"
#include "Adafruit_BMP085.h"


ADXL345 acel = ADXL345();
Adafruit_BMP085 bmp;

struct Eixo{
  int acelX, acelY, acelZ;
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
  //detecção de queda
  //registra interrupção actions - 1 == on; 0 == off  
  acel.setInterrupt( ADXL345_INT_FREE_FALL_BIT,  1);


  //Limite da queda e duração
   acel.setFreeFallThreshold(7);// //(5 - 9) recommended - 62.5mg per increment
   acel.setFreeFallDuration(20); // //(20 - 70) recommended - 5ms per increment
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
  Serial.write("T");
}

void checkSetup()
{
  Serial.print("Free Fall Threshold = ");
  Serial.println(acel.getFreeFallThreshold());
  Serial.print("Free Fall Duration = ");
  Serial.println(acel.getFreeFallDuration());
}

void loop() {
  acel.readAccel(&eixos.acelX,&eixos.acelY,&eixos.acelZ);

  altitude = bmp.readAltitude();
  checkSetup();
  enviarEixos();
  enviarAltitude();
  
  
 // Leitura interrompe fonte e procurar ações desencadeadas
  byte interrupts = acel.getInterruptSource();
  if(acel.triggered(interrupts, ADXL345_FREE_FALL)){
    Serial.println("FreeFall - Queda detectada");
    // adicionar código aqui para fazer algo quando a queda livre for detectada
    
  }
 

  delay(2000);
}
