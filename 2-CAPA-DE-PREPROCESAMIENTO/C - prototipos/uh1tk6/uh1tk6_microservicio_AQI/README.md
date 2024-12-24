# Uh1tk6: Desarrollar microservicio básico para recolección de datos

## Descripción General

Este proyecto tiene como objetivo desarrollar un microservicio utilizando un ESP32-Wroom de 38 pines para la recolección de datos de tres sensores: **MQ135**, **AHT25** y **BMP280**.   
El sistema está diseñado para ser escalable y fácil de mantener, con cada sensor gestionado por un módulo independiente.  
Los datos recogidos son filtrados y mostrados en el monitor serie.

## Estructura del Proyecto

lib/   
├── MQ135Sensor.cpp   
├── MQ135Sensor.h   
├── AHT25Sensor.cpp   
├── AHT25Sensor.h   
├── BMP280Sensor.cpp   
├── BMP280Sensor.h   
src/  
├── main.cpp

  

## Descripción de los Módulos

## 1. **main.cpp**

En este modulo se maneja la ejecución del programa, inicializando cada uno de los módulos de sensores y gestionando el bucle principal donde se realizan las lecturas de datos. Los datos obtenidos de cada sensor se filtran para eliminar valores erróneos y se muestran en el monitor serie.

### Flujo de trabajo en `main.cpp`:
- Inicializa el sistema de sensores en el `setup()`.
- Realiza lecturas cíclicas en el `loop()`, llamando a los métodos de cada módulo sensor.
- Muestra los datos en el monitor serie y maneja la lógica básica de filtrado.

## 2. **MQ135Sensor.h y MQ135Sensor.cpp**

Estos archivos implementan la clase `MQ135Sensor`, encargada de gestionar el sensor **MQ135** que mide la calidad del aire. El sensor MQ135 puede detectar concentraciones de gas entre 10 y 1000 ppm y es útil para la detección de gases nocivos como amoniaco, dióxido de nitrógeno, alcohol, benceno, dióxido y monóxido de carbono.   

### Funciones clave:
- `begin()`:   
Inicializa el sensor y configura el filtro de media móvil para suavizar las lecturas.
- `readFilteredData()`:   
Lee los datos del sensor, aplica un filtro de media móvil para suavizar las lecturas y descarta valores fuera de un rango predefinido (10-1000 PPM).   
Devuelve el valor filtrado o -1 si la lectura es inválida.  

### Que es un filtro de media movil?
Un filtro de media móvil es un método numérico utilizado para reducir el ruido y la volatilidad en una serie de datos, permitiendo visualizar tendencias y patrones más claros. Su función básica es calcular la media de los valores más recientes de la serie y utilizarla como una aproximación más estable de la tendencia actual.

En términos prácticos, un filtro de media móvil se aplica de la siguiente manera:

1. Se define un tamaño de ventana (N) que indica cuántos valores más recientes se consideran para calcular la media.
2. Se itera sobre la serie de datos, empezando desde el primer valor y hasta el valor actual.
3. Se calcula la media de los N valores más recientes, descartando el primer valor de la ventana al calcular la media y añadiendo el nuevo valor.
3. El resultado es el valor filtrado, que se utiliza como una estimación más estable de la tendencia actual.   

**Ventajas y desventajas**  
* Ventajas:   
  - sencillo de implementar  
  - Rápido de calcular   
  - Eficaz para reducir el ruido de alta frecuencia.  

* Desventajas:   
  - Puede eliminar componentes auténticos de la señal si el tamaño de la ventana es demasiado grande.   
  - Puede ser débil para detectar cambios bruscos en la tendencia.

**Características del MQ135:**
- **Tipo:** Sensor analógico
- **Conexión:** Pin analógico (GPIO34)
- **Filtro:** Media móvil con 10 lecturas

## 3. **AHT25Sensor.h y AHT25Sensor.cpp**

Estos archivos implementan la clase `AHT25Sensor`, responsable de gestionar el sensor **AHT25** que mide temperatura y humedad relativa.

### Funciones clave:
- `begin()`:   
Inicializa el sensor **AHT25** y verifica su disponibilidad en el bus I2C.  

- `readData(float &temperature, float &humidity)`:   
Lee los datos de temperatura y humedad desde el sensor.   
Aplicando un filtro que descarta valores fuera de los rangos aceptables.   
Devuelve `true` si los datos son válidos y `false` si no lo son.

**Características del AHT25:**
- **Tipo:** Sensor digital (I2C)
- **Conexión:** I2C (GPIO21 - SDA, GPIO22 - SCL)
- **Rangos de validación:**
  - **Temperatura:** -40°C a 80°C
  - **Humedad:** 0% a 100%

## 4. **BMP280Sensor.h y BM2p80Sensor.cpp**

Estos archivos implementan la clase `BMP280Sensor`, que gestiona el sensor **BMP280** para la medición de temperatura, presión barométrica y humedad relativa.

### Funciones clave:
- `begin()`:   
Inicializa el sensor **BMP280** y verifica su disponibilidad en el bus I2C.  

- `readData(float &temperature, float &pressure)`:   
Lee los datos de temperatura, y presión del sensor.   
Aplica filtros para descartar valores fuera de rangos predefinidos.   
Devuelve `true` si los datos son válidos y `false` si no lo son.

**Características del BME280:**
- **Tipo:** Sensor digital (I2C)
- **Conexión:** I2C (GPIO21 - SDA, GPIO22 - SCL)
- **Rangos de validación:**
  - **Temperatura:** -40°C a 80°C
  - **Presión:** 300 hPa a 1100 hPa
  

## **Librerias necesarias**

Para que el programa funcione es necesario instalar las siguientes librerias en el IDE:  

- **Adafruit BMP280.h**
- **Adafruit AHTX0.h**
- **MQ135.h**   

Para el caso de PlatformIO la mismas pueden instalarse desde el gestor de librerias buscando el nombre de cada una, y haciendo click en `install`.  

### 2. **Configuración de Hardware**

Los sensores se conectan al ESP32-Wroom según las siguientes especificaciones:

- **MQ135 (Analógico):**
  - **VCC:** 3.3V
  - **GND:** GND
  - **Salida de señal:** GPIO36 (ADC1_CH0)
  
- **AHT25 (I2C):**
  - **VCC:** 3.3V
  - **GND:** GND
  - **SDA:** GPIO21
  - **SCL:** GPIO22
  
- **BMP280 (I2C):**
  - **VCC:** 3.3V
  - **GND:** GND
  - **SDA:** GPIO21
  - **SCL:** GPIO22

### 3. **Compilación y Carga del Código**

Seguir los siguientes pasos:  

1. Abrir el proyecto en el IDE Platformio o en VScode con Platformio integrado.
2. Seleccionar la placa **ESP32 Dev Module** en el menú **Tools > Board**.
3. Seleccionar el puerto correcto donde está conectado el ESP32.
4. Compilar y cargar el código en el ESP32.

### 4. **Monitoreo de Datos**

Abrir el **Monitor Serie** en el IDE y configurarlo a **115200 baudios** para observar las lecturas de los sensores. Los datos se mostrarán en tiempo real y se indicará si alguna lectura es inválida debido a valores fuera de los rangos definidos.

## Futuras Expansiones

Este proyecto está diseñado para ser fácilmente escalable.   
Se puedes agregar más sensores o funcionalidades, como enviar los datos a una plataforma en la nube o a un servidor remoto.   
El código modular facilita la incorporación de nuevas características sin afectar la estructura existente.

## Licencia

Este proyecto está licenciado bajo la Licencia Creative Commons Atribución-NoComercial (CC BY-NC). Esta licencia permite que otros remixen, adapten y construyan sobre el trabajo de forma no comercial y, aunque sus nuevos trabajos deben también reconocer al autor original y ser no comerciales, no tienen que licenciar sus obras derivadas en los mismos términos.

Esta licencia es adecuada para un uso educativo y de aprendizaje, permitiendo la libre distribución y utilización del material mientras se protege contra el uso comercial sin autorización previa. Para usos comerciales, es necesario contactar a los autores para obtener permiso.

Para obtener más información sobre esta licencia y ver una copia completa de sus términos, visite [Creative Commons Atribución-NoComercial (CC BY-NC)](https://creativecommons.org/licenses/by-nc/4.0/).