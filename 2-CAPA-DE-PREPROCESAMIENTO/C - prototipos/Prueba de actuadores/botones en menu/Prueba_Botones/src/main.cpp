#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección I2C del LCD (ajustar según tu modelo)
const int addr = 0x27;

// Pines de los botones (ajustar según tu conexión)
const int boton1 = 2;
const int boton2 = 15;
const int boton3 = 4;

// Crear un objeto LCD
LiquidCrystal_I2C lcd(addr, 16, 2);

// Variables para los datos de los sensores (ampliado)
float temperatura = 25.0;
int humedad = 50;
float presion = 1013.25; // en hPa
float radiacionUV = 2; // en mW/cm²
int cantidadLuz = 500; // valor arbitrario
int particulasGas = 120; // partículas por cm³
int co2 = 400; // ppm

// Variable para controlar el estado de la pantalla
bool pantallaEncendida = true;

// Variable para controlar si se debe mostrar el mensaje de bienvenida
bool mostrarBienvenida = false;

// Variable para controlar el conjunto de datos a mostrar
int conjuntoDatos = 1;

void setup() {
  // Inicializar la comunicación I2C
  Wire.begin();

  // Inicializar el LCD
  lcd.init();

  // Configurar los pines de los botones como entrada
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(boton3, INPUT_PULLUP);
}

void loop() {
  // Leer los valores de los sensores (aquí iría tu código para leer los sensores)

  // Manejar los eventos de los botones
  if (digitalRead(boton1) == LOW) {
  conjuntoDatos++;
  // Asegurar que conjuntoDatos no sea mayor a 3
  if (conjuntoDatos > 3) {
    conjuntoDatos = 3; //entendiendo como 3 la cantidad de casos en datos por pares a mostrar
  }
}

if (digitalRead(boton2) == LOW) {
  conjuntoDatos--;
  // Asegurar que conjuntoDatos no sea menor a 0
  if (conjuntoDatos < 1) {
    conjuntoDatos = 1;
  }
}



  if (digitalRead(boton3) == LOW) {
    pantallaEncendida = !pantallaEncendida;
    if (pantallaEncendida) {
      mostrarBienvenida = true; // Mostrar mensaje de bienvenida
    }
  }

  // Mostrar los datos en el LCD
  if (pantallaEncendida) {
    if (mostrarBienvenida) {
      lcd.clear();
      lcd.print("Bienvenido!");
      delay(2000); // Esperar 2 segundos
      mostrarBienvenida = false; // Reiniciar la bandera
      conjuntoDatos = 1; // Volver al primer conjunto de datos
    } else {
      lcd.clear();
      switch (conjuntoDatos) {
        case 1:
          // Temperatura y humedad
          lcd.setCursor(0, 0);
          lcd.print("Temp: ");
          lcd.print(temperatura);
          lcd.print("C");
          lcd.setCursor(0, 1);
          lcd.print("Hum: ");
          lcd.print(humedad);
          lcd.print("%");

          break;
        case 2:
          // Presión, radiación UV y luz
          lcd.setCursor(0, 0);
          lcd.print("Presion: ");
          lcd.print(presion);
          lcd.print("hPa");
          lcd.setCursor(0, 1);
          lcd.print("UV: ");
          lcd.print(radiacionUV);
          lcd.print("mW/cm²");
          break;
        case 3:
          // Partículas de gas y CO2
          lcd.setCursor(0, 0);
          lcd.print("PartGas: ");
          lcd.print(particulasGas);
          lcd.setCursor(0, 1);
          lcd.print("CO2: ");
          lcd.print(co2);
          lcd.print("ppm");
          break;
        // Agregar más casos según sea necesario
      }
    }
  }

  delay(100); // Pequeño retraso para evitar sobrecargar el procesador
}