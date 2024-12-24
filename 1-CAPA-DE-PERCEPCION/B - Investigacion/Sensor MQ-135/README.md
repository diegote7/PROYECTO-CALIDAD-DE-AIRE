# MQ-135 Gas Sensor

## Características

- Amplio rango de detección
- Alta sensibilidad y respuesta rápida
- Estable y de larga vida útil
- Circuito de manejo simple

## Aplicaciones

- Equipos de control de calidad del aire en edificios y oficinas.
- Adecuado para la detección de NH3, NOx, alcohol, benceno, humo, CO2, etc.

## Especificaciones

### A → Condiciones de trabajo estándar

| Símbolo | Nombre del parámetro       | Condición técnica | Observaciones        |
| ------- | -------------------------- | ----------------- | -------------------- |
| Vc      | Voltaje del circuito       | 5V ± 0.1          | AC o DC              |
| VH      | Voltaje de calentamiento   | 5V ± 0.1          | AC o DC              |
| RL      | Resistencia de carga       | Ajustable         |                      |
| RH      | Resistencia del calentador | 33Ω ± 5%          | Temperatura ambiente |
| PH      | Consumo de calentamiento   | < 800 mW          |                      |

### B → Condiciones ambientales

| Símbolo | Nombre del parámetro          | Condición técnica        | Observaciones                                                                                |
| ------- | ----------------------------- | ------------------------ | -------------------------------------------------------------------------------------------- |
| Tao     | Temperatura de uso            | -10°C a 45°C             |                                                                                              |
| Tas     | Temperatura de almacenamiento | -20°C a 70°C             |                                                                                              |
| RH      | Humedad relativa              | < 95% RH                 |                                                                                              |
| O2      | Concentración de oxígeno      | 21% (condición estándar) | La concentración de oxígeno puede afectar la sensibilidad, el valor mínimo es superior al 2% |

### C → Características de sensibilidad

| Símbolo | Nombre del parámetro       | Parámetro técnico       | Observaciones |
| ------- | -------------------------- | ----------------------- | ------------- |
| Rs      | Resistencia de detección   | 30KΩ-200KΩ (100ppm NH3) |               |
| α       | Tasa de pendiente (200/50) | ≤ 0.65                  |               |

#### Condición estándar de detección

- Temperatura: 20°C ± 2°C
- Voltaje del circuito: 5V ± 0.1V
- Humedad: 65% ± 5%
- Voltaje de calentamiento: 5V ± 0.1V
- Tiempo de pre-calentamiento: más de 24 horas

#### Rango de concentración de detección

- 10ppm - 300ppm NH3
- 10ppm - 1000ppm Benceno
- 10ppm - 300ppm Alcohol

## D → Estructura y configuración, circuito de medición básico

El sensor de gas MQ-135 está compuesto por un tubo cerámico de Al2O3, una capa sensible de dióxido de estaño (SnO2), electrodos de medición y un calentador, todos fijados en una base de resina y una red de acero inoxidable a prueba de explosiones. El calentador proporciona las condiciones necesarias para el funcionamiento de la capa sensible.

### Materiales de las partes

- Capa de detección de gas: SnO2
- Electrodo: Au
- Línea de electrodo: Pt
- Bobina del calentador: Aleación de Ni-Cr
- Tubo cerámico: Al2O3
- Red a prueba de explosiones: Malla de acero inoxidable (SUS316 100-mesh)
- Anillo de sujeción: Cobre con niquelado
- Base de resina: Baquelita
- Pata del tubo: Cobre con niquelado

## E → Curva de características de sensibilidad

La curva muestra la sensibilidad del MQ-135 para varios gases bajo condiciones específicas: temperatura de 20°C, humedad del 65%, concentración de oxígeno del 21% y resistencia de carga (RL) de 20kΩ.

### Ajuste de sensibilidad

El valor de la resistencia del MQ-135 varía con diferentes tipos y concentraciones de gases. Es necesario ajustar la sensibilidad calibrando el detector para 100ppm de NH3 o 50ppm de Alcohol en aire y utilizando un valor de resistencia de carga (RL) de aproximadamente 20 kΩ (10kΩ a 47kΩ). Para mediciones precisas, se debe determinar el punto de alarma adecuado del detector de gas considerando la influencia de la temperatura y la humedad.

### Dependencia de la temperatura y la humedad

La resistencia del sensor (Rs) varía con la temperatura y la humedad. La curva de la figura 4 muestra esta dependencia para 100ppm de NH3 en aire a diferentes temperaturas y humedades.

---

Para más detalles y especificaciones, por favor consulte el documento técnico completo.
