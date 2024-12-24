# Filtrado y Suavizado de Lecturas de Sensores

## Introducción

En proyectos de IoT y sistemas embebidos, la lectura de datos de sensores puede verse afectada por ruido, interferencias o fluctuaciones que no representan fielmente el fenómeno que se está midiendo. Para mejorar la calidad de los datos obtenidos, se utilizan técnicas de filtrado y suavizado que ayudan a reducir el ruido y obtener lecturas más estables y precisas.

Este documento explora varias técnicas de filtrado, desde las más simples hasta las más avanzadas, y proporciona ejemplos prácticos de implementación en un microcontrolador como el ESP32.

## Métodos de Filtrado y Suavizado

### 1. **Media Móvil (Moving Average)**

#### **Teoría:**
La media móvil es un método simple que suaviza una serie de datos calculando el promedio de un subconjunto de las lecturas más recientes. A medida que se obtiene una nueva lectura, se elimina la más antigua del subconjunto y se recalcula la media.

#### **Ventajas:**
- Fácil de implementar.
- Suaviza las fluctuaciones rápidas en los datos.

#### **Desventajas:**
- Introduce un retraso en la señal.
- Puede no ser efectivo para filtrar ruidos impulsivos o picos.

#### **Ejemplo Práctico en C++ (Arduino):**

```cpp
const int NUM_READINGS = 10;
float readings[NUM_READINGS]; // Array de lecturas
int readIndex = 0;
float total = 0;
float average = 0;

void setup() {
    // Inicialización del array
    for (int i = 0; i < NUM_READINGS; i++) {
        readings[i] = 0;
    }
}

float getFilteredReading(float newReading) {
    total -= readings[readIndex]; // Resta la lectura más antigua
    readings[readIndex] = newReading; // Añade la nueva lectura
    total += readings[readIndex]; // Suma la nueva lectura al total
    readIndex = (readIndex + 1) % NUM_READINGS; // Avanza el índice
    average = total / NUM_READINGS; // Calcula la media
    return average;
}
```

### **2. Filtro de Mediana (Median Filter)**  

#### **Teoría:**  
El filtro de mediana es una técnica no lineal que consiste en ordenar un subconjunto de las lecturas recientes y seleccionar la mediana (el valor central). Este método es particularmente efectivo para eliminar picos de ruido (outliers) que no representan la tendencia general de los datos.

#### **Ventajas:**  
Elimina eficazmente picos de ruido y valores atípicos.
No introduce un retraso tan significativo como la media móvil.  

#### **Desventajas:**
Puede ser más costoso computacionalmente que la media móvil.
No es adecuado para señales con cambios muy rápidos.  

#### **Ejemplo Práctico en C++ (Arduino):**  

```cpp
#include <algorithm> // Necesario para std::sort

const int NUM_READINGS = 5;
float readings[NUM_READINGS]; // Array de lecturas

float getMedianFilteredReading(float newReading) {
    readings[readIndex] = newReading; // Añade la nueva lectura
    readIndex = (readIndex + 1) % NUM_READINGS; // Avanza el índice

    // Copia el array para ordenar
    float sortedReadings[NUM_READINGS];
    memcpy(sortedReadings, readings, sizeof(sortedReadings));

    // Ordena el array
    std::sort(sortedReadings, sortedReadings + NUM_READINGS);

    // Devuelve la mediana (valor central)
    return sortedReadings[NUM_READINGS / 2];
}
```
### **3. Filtro Exponencial (Exponential Moving Average - EMA)**  

#### **Teoría:**  

El filtro exponencial pondera más las lecturas recientes y menos las lecturas antiguas. Se calcula como una combinación ponderada de la lectura actual y la media anterior. Esto permite una mayor sensibilidad a cambios recientes sin perder completamente la influencia del historial de datos.

#### **Fórmula:**  
  
$$ EMA_{n} = \alpha \times X_{n} + (1 - \alpha) \times EMA_{n-1} $$
​
  donde:    

**α** es el factor de suavizado, entre 0 y 1. 
  
**Xn**  es la lectura actual.  

**EMAn-1** es la media anterior.  

#### **Ventajas:**  

Más reactivo a cambios recientes que la media móvil.
Suaviza ruidos sin retrasar significativamente la señal.  

### **Desventajas:**
La elección de α puede ser crítica y depende del tipo de señal.  

Ejemplo Práctico en C++ (Arduino):  
```cpp  
float alpha = 0.1; // Factor de suavizado
float ema = 0; // Inicializa EMA

float getEMAFilteredReading(float newReading) {
    ema = alpha * newReading + (1 - alpha) * ema;
    return ema;
}
```    

### **4. Filtro Kalman**  

#### **Teoría:**  

El filtro Kalman es un método recursivo que estima el estado de un sistema dinámico a partir de una serie de mediciones ruidosas. Es altamente efectivo en la estimación y filtrado de señales donde la relación entre la medición y el estado subyacente del sistema es lineal.

#### **Ventajas:**  

Ideal para sistemas donde se necesita una estimación precisa y filtrada en tiempo real.
Considera tanto la incertidumbre de la medición como la incertidumbre del modelo.  

#### **Desventajas:**  

Es más complejo de implementar que otros filtros.
Requiere conocer el modelo del sistema y las estadísticas de ruido.  

#### **Ejemplo Práctico en C++ (Arduino):**  
```cpp  
float Q = 0.1; // Variancia del proceso (ruido)
float R = 0.1; // Variancia de la medición
float P = 1;   // Error de estimación inicial
float K = 0;   // Ganancia de Kalman
float X = 0;   // Estimación inicial

float getKalmanFilteredReading(float newReading) {
    // Predicción
    P = P + Q;

    // Actualización
    K = P / (P + R);
    X = X + K * (newReading - X);
    P = (1 - K) * P;

    return X;
}
```  
  
### **5. Filtro Promedio Ponderado (Weighted Moving Average)**  

#### **Teoría:**  

El filtro promedio ponderado asigna diferentes pesos a las lecturas recientes, donde las lecturas más recientes tienen mayor peso que las más antiguas. Esto permite un filtrado que es más sensible a las últimas mediciones sin perder la influencia de las anteriores.

#### **Ventajas:**  

Proporciona un compromiso entre la suavidad de la señal y la capacidad de respuesta.
Puede ajustarse fácilmente cambiando los pesos.  

#### **Desventajas:**  

Requiere la elección de pesos adecuados.
Puede ser más complicado de implementar que la media móvil simple.  

#### **Ejemplo Práctico en C++ (Arduino): **    

```cpp  
const int NUM_READINGS = 5;
float weights[NUM_READINGS] = {0.1, 0.2, 0.3, 0.4, 0.5}; // Pesos para cada lectura
float readings[NUM_READINGS];

float getWeightedAverageFilteredReading(float newReading) {
    readings[readIndex] = newReading;
    readIndex = (readIndex + 1) % NUM_READINGS;

    float weightedSum = 0;
    for (int i = 0; i < NUM_READINGS; i++) {
        weightedSum += readings[i] * weights[i];
    }

    return weightedSum;
}
```  

El filtrado y el suavizado de datos son esenciales en proyectos que involucran la lectura de sensores, especialmente en entornos ruidosos o fluctuantes.   
Cada método tiene sus ventajas y desventajas, y la elección del método adecuado depende de las características específicas del sistema y los requisitos del proyecto.

Para proyectos simples, la media móvil o el filtro exponencial suelen ser suficientes.   
Sin embargo, para aplicaciones más críticas donde se requiere alta precisión y eliminación de ruido, métodos como el filtro Kalman son más adecuados.



- **Media Móvil:** Ideal para suavizar fluctuaciones menores en señales estables.  

- **Filtro de Mediana:** Excelente para eliminar valores atípicos en señales con ruido impulsivo.  

- **Filtro Exponencial:** Útil cuando se necesita un balance entre sensibilidad a cambios y suavizado.  

- **Filtro Kalman:** Recomendado para sistemas dinámicos complejos donde se requiere una estimación precisa en tiempo real.  

- **Promedio Ponderado:** Útil para ajustar la importancia relativa de lecturas pasadas en sistemas donde las condiciones cambian rápidamente.  

La combinación o el ajuste de estos métodos pueden resultar en un sistema de filtrado altamente eficiente, por ejemplo en el proyecto de monitoreo de la calidad del aire (AQI) que estamos desarrollando, es crucial asegurar la precisión y confiabilidad de las lecturas de los sensores, ya que el dispositivo estará expuesto a condiciones ambientales variables, incluyendo temperatura, humedad, y potenciales interferencias electromagnéticas. Dado que el dispositivo estará ubicado en un gabinete estanco en la calle, los sensores estarán sujetos a fluctuaciones rápidas y picos de ruido que podrían afectar la calidad de los datos. Para mitigar estos problemas, proponemos la combinación de varios filtros, cada uno diseñado para abordar diferentes tipos de ruido e inestabilidades en las lecturas.

## Sensores Involucrados

1. **MQ135**: Sensor de gases que mide la concentración de CO2, NOx, y otros gases contaminantes.
2. **AHT25**: Sensor de temperatura y humedad relativa.
3. **BME280**: Sensor que mide temperatura, presión barométrica y humedad relativa.

## Propuesta de Combinación de Filtros

### 1. **Media Móvil + Filtro de Mediana**

#### **Descripción:**
Combinar un filtro de **Media Móvil** con un **Filtro de Mediana** permite suavizar las lecturas mientras se eliminan picos de ruido significativos. Esta combinación es particularmente útil para sensores como el **MQ135**, que puede estar expuesto a picos de contaminantes debido a cambios bruscos en las condiciones ambientales (por ejemplo, el paso de vehículos).

#### **Implementación:**

- **Media Móvil:** Se aplica primero para suavizar las lecturas y reducir fluctuaciones menores.
- **Filtro de Mediana:** Posteriormente, se aplica un filtro de mediana sobre el conjunto de lecturas suavizadas para eliminar outliers.

**Código Ejemplo:**

```cpp
const int NUM_READINGS = 10;
float readings[NUM_READINGS];
int readIndex = 0;
float total = 0;
float average = 0;

float getFilteredReading(float newReading) {
    total -= readings[readIndex];
    readings[readIndex] = newReading;
    total += readings[readIndex];
    readIndex = (readIndex + 1) % NUM_READINGS;
    average = total / NUM_READINGS;

    // Aplicar filtro de mediana
    float sortedReadings[NUM_READINGS];
    memcpy(sortedReadings, readings, sizeof(sortedReadings));
    std::sort(sortedReadings, sortedReadings + NUM_READINGS);

    // Devuelve la mediana del promedio móvil
    return sortedReadings[NUM_READINGS / 2];
}  
```  
### **2. Filtro Exponencial + Filtro de Mediana**  

#### **Descripción:**
El Filtro Exponencial (EMA) responde rápidamente a cambios recientes en las condiciones ambientales, pero sin perder la suavidad en los datos. Combinado con un Filtro de Mediana, es posible eliminar picos de ruido mientras se mantiene la sensibilidad del sistema a cambios ambientales rápidos.

Esta combinación es ideal para sensores como el AHT25 y el BME280, que miden variables ambientales críticas como la temperatura y la humedad, donde los cambios bruscos pueden ser indicativos de condiciones significativas.

#### **Implementación:**  

- **Filtro Exponencial:** Se aplica primero para darle más peso a las lecturas recientes, suavizando la señal de forma dinámica.
- **Filtro de Mediana:** Se utiliza después para eliminar outliers generados por interferencias esporádicas.  

#### **Código Ejemplo:**  
```cpp  
float alpha = 0.2;
float ema = 0;

float getEMAFilteredReading(float newReading) {
    ema = alpha * newReading + (1 - alpha) * ema;

    // Aplicar filtro de mediana sobre las últimas 5 lecturas del EMA
    const int NUM_READINGS = 5;
    float emaReadings[NUM_READINGS];
    static int index = 0;

    emaReadings[index] = ema;
    index = (index + 1) % NUM_READINGS;

    float sortedEmaReadings[NUM_READINGS];
    memcpy(sortedEmaReadings, emaReadings, sizeof(sortedEmaReadings));
    std::sort(sortedEmaReadings, sortedEmaReadings + NUM_READINGS);

    return sortedEmaReadings[NUM_READINGS / 2];
}
```  
### **3. Filtro Kalman + Filtro Exponencial**  

#### **Descripción:**  

El Filtro Kalman es altamente efectivo en sistemas donde las mediciones están sujetas a ruido, y se requiere una estimación precisa del estado del sistema. Al combinarlo con un Filtro Exponencial, se obtiene un sistema de filtrado que no solo suaviza los datos, sino que también predice y corrige las lecturas basándose en el modelo del sistema.

Esta combinación es adecuada para sistemas críticos como el AQI, donde se necesitan lecturas precisas y filtradas en tiempo real para decisiones automatizadas.

#### **Implementación:**  

- **Filtro Kalman:** Se aplica primero para estimar el valor más probable de la señal basándose en mediciones previas y la dinámica del sistema.
- **Filtro Exponencial:** Se utiliza para suavizar la señal estimada por Kalman y mejorar la respuesta del sistema a cambios rápidos.  

#### **Código Ejemplo:**  
```cpp  
float Q = 0.1;
float R = 0.1;
float P = 1;
float K = 0;
float X = 0;
float alpha = 0.2;
float ema = 0;

float getKalmanFilteredReading(float newReading) {
    P = P + Q;
    K = P / (P + R);
    X = X + K * (newReading - X);
    P = (1 - K) * P;

    // Aplicar filtro exponencial
    ema = alpha * X + (1 - alpha) * ema;
    return ema;
}
```  
  
### **Consideraciones para la Implementación**
#### **Condiciones Ambientales:**  

- **Protección de Sensores:** Aunque los sensores estarán protegidos en un gabinete estanco, la exposición directa al ambiente puede introducir ruido debido a variaciones rápidas en las condiciones externas (como ráfagas de viento, lluvia, cambios de temperatura súbitos, etc.). Estos filtros ayudarán a mitigar los efectos de estas variaciones.

- **Latencia vs. Precisión:** Es importante encontrar un equilibrio entre la latencia y la precisión en las lecturas. Filtros como el Kalman pueden introducir un pequeño retraso, pero proporcionan una mayor precisión, lo cual es crucial en aplicaciones de monitoreo ambiental como el AQI.

#### **Configuración y Ajuste de Parámetros:**
- **Factores de Suavizado:** Los parámetros como 𝛼 en el Filtro Exponencial o los valores de 𝑄 y 𝑅 en el Filtro Kalman deben ajustarse cuidadosamente basándose en pruebas de campo. Esto asegura que los filtros respondan adecuadamente a las condiciones reales sin sobre-suavizar las lecturas.

- **Tamaño de Ventana en Filtros de Mediana y Media Móvil:** El tamaño de la ventana (número de lecturas consideradas) es crucial. Ventanas más grandes proporcionan un mayor suavizado, pero pueden perder detalles importantes en cambios rápidos. Se recomienda realizar pruebas empíricas para determinar el tamaño óptimo.

#### **Conclusión**  

La combinación de filtros es una estrategia poderosa para mejorar la calidad de las lecturas de sensores en entornos difíciles como los que enfrentará el proyecto AQI. Al combinar técnicas de suavizado como la Media Móvil, la Mediana y el Filtro Exponencial, con métodos más avanzados como el Filtro Kalman, podemos obtener datos más precisos y confiables, lo que es crucial para el monitoreo ambiental en tiempo real.

Esta metodología no solo ayudará a filtrar el ruido y las interferencias, sino que también proporcionará un sistema robusto capaz de adaptarse a las fluctuaciones ambientales, asegurando así una medición precisa y consistente de la calidad del aire.
