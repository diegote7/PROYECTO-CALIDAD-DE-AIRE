# PROYECTO CALIDAD DE AIRE

[![Designer-7.jpg](https://i.postimg.cc/JtwXG50r/Designer-7.jpg)](https://postimg.cc/wRVMrJDZ) 

Descripcion: 

El proyecto está orientado al diseño, desarrollo e implementación de un sistema de monitoreo de calidad de aire basado en tecnologías IoT, con el objetivo de registrar, analizar y presentar datos ambientales relevantes en tiempo real. Este sistema utiliza una combinación de sensores, microcontroladores y módulos de comunicación para capturar información clave y facilitar la toma de decisiones en entornos que requieren un control ambiental eficiente.

Componentes del Sistema

Microcontrolador:

ESP32-Wroom: Central del sistema por su capacidad de conectividad (WiFi y Bluetooth) y procesamiento.

Sensores:

MQ135: Detecta gases tóxicos y mide la calidad general del aire.
AHT25: Mide la temperatura y la humedad relativa del ambiente.
BMP280: Sensor de presión barométrica para estimar altitud y condiciones climáticas.
Actuadores y Salidas:

Display LCD: Presenta la información recolectada de manera visual en tiempo real.
Tira LED WS2812: Proporciona una representación visual de los niveles de calidad del aire mediante colores intuitivos.
Módulos de Comunicación:

Bluetooth Low Energy (BLE): Permite transmitir datos a dispositivos móviles cercanos para el monitoreo local.
WiFi: Para enviar información a una plataforma en la nube y habilitar el monitoreo remoto.
Funcionamiento
El sistema recolecta datos de los sensores en tiempo real, los procesa en el microcontrolador ESP32 y utiliza algoritmos para analizar la calidad del aire. Los resultados se presentan en el display LCD y la tira LED, donde el cambio de colores indica la condición del aire: desde óptima hasta peligrosa. Además, los datos se transmiten vía BLE o WiFi para visualización remota y almacenamiento en la nube.

Objetivos del Proyecto
Monitorear la Calidad del Aire: Detectar y registrar niveles de gases y parámetros ambientales críticos.
Alertar Condiciones de Riesgo: Notificar cambios en la calidad del aire mediante salidas visuales y notificaciones remotas.
Facilitar la Toma de Decisiones: Proveer información precisa y en tiempo real para mitigar riesgos ambientales.
Promover la Movilidad del Sistema: Integrar comunicación BLE y WiFi para el monitoreo desde múltiples plataformas.
Aplicaciones

Este sistema puede implementarse en:

Espacios urbanos con alta contaminación.
Áreas industriales para controlar emisiones.
Entornos rurales para evaluar condiciones climáticas y agrícolas.
El proyecto combina tecnologías avanzadas y accesibles para ofrecer una solución eficiente y escalable en el monitoreo ambiental, contribuyendo al bienestar y la sostenibilidad.






