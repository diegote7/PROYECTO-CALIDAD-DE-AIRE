#include <Arduino.h>
#include <MQ135.h>  // Incluir la librería MQ135


int mq135Pin = 34; // Pin analógico conectado al AO del sensor MQ135

void setup() {
  Serial.begin(115200); // Iniciar la comunicación serial a 115200 bps
}

void loop() {
  int sensorValue = analogRead(mq135Pin); // Leer el valor del sensor MQ135
  Serial.print("Valor del sensor MQ135: "); // Imprime un mensaje en la terminal
  Serial.println(sensorValue); // imprme el valor del sensor en la terminal 
  delay(1000); // Esperar un segundo antes de la siguiente lectura
}