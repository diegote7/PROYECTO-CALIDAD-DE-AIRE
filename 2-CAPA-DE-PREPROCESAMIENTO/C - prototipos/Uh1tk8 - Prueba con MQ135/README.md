# Practica y prueba del sensor MQ-135
## Componentes Utilizados

- **ESP32**: Un microcontrolador con capacidades Wi-Fi y Bluetooth.
- **Sensor MQ-135**: Sensor de gas que puede detectar una variedad de gases, incluyendo amoníaco, sulfuro de hidrógeno, benceno, y dióxido de carbono.
- **Cables de conexión**: Para conectar el sensor al ESP32.
- **Fuente de alimentación**: Para alimentar el ESP32 y el sensor.

## Conexiones

El sensor MQ-135 se conecta al ESP32 de la siguiente manera:

- **VCC** del MQ-135 a **3.3V** en el ESP32.
- **GND** del MQ-135 a **GND** en el ESP32.
- **Analog Out** del MQ-135 a un pin de entrada analógica del ESP32 (por ejemplo, **GPIO 34**).


