#include <Arduino.h>
#include <Wire.h>
#include "MQ135Sensor.h"
#include "AHT25Sensor.h"
#include "BMP280Sensor.h"

// --------------------- Configuración de Pines ---------------------
#define MQ135_PIN 36 // GPIO36 (ADC1_CH6)

// --------------------- Inicialización de Sensores ---------------------
MQ135Sensor mq135(MQ135_PIN);
AHT25Sensor aht25;
BMP280Sensor bmp280;

// --------------------- Configuración Inicial ---------------------
void setup() {
    Serial.begin(115200);
    while (!Serial);

    Serial.println("Inicializando sensores...");

    Wire.begin();
    mq135.begin();
    aht25.begin();
    bmp280.begin();

    Serial.println("Todos los sensores están listos.");
}

// --------------------- Bucle Principal ---------------------
void loop() {
    // Lectura y filtrado de datos del MQ135
    float mq135Data = (float) mq135.readFilteredData();
    if (mq135Data == -1) {
        Serial.println("Lectura MQ135 inválida.");
    } else {
        Serial.print("MQ135 PPM: ");
        Serial.println(mq135Data);
    }

    // Lectura y filtrado de datos del AHT25
    float ahtTemp, ahtHumidity;
    if (aht25.readData(ahtTemp, ahtHumidity)) {
        Serial.print("AHT25 Temperatura: ");
        Serial.print(ahtTemp);
        Serial.println(" *C");

        Serial.print("AHT25 Humedad: ");
        Serial.print(ahtHumidity);
        Serial.println(" %");
    } else {
        Serial.println("Lectura AHT25 inválida.");
    }

    // Lectura y filtrado de datos del BMP280
    float bmpTemp, bmpPressure;
    if (bmp280.readData(bmpTemp, bmpPressure)) {
        Serial.print("BMP280 Temperatura: ");
        Serial.print(bmpTemp);
        Serial.println(" *C");

        Serial.print("BMP280 Presión: ");
        Serial.print(bmpPressure);
        Serial.println(" hPa");
    } else {
        Serial.println("Lectura BMP280 inválida.");
    }

    Serial.println("---------------------------");
    delay(2000);
}