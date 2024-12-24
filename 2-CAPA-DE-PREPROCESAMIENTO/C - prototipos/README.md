# Proyecto Integrador I 
## Instituto: ISPC  
**Carrera:** Tecnicatura Superior en Telecomunicaciones.  
**Materia:** Proyecto Integrador I  
**Docente:** Cristian Gonzalo Vera  

## Grupo: PLATA
<h1> Docente </h1>
        <table align="center">
          <thead>
            <tr>
              <th>Nombre y Apellido</th>
              <th>Usuario en GitHub</th>
              <th>GitHub</th>
            </tr>
          </thead>
          <tbody>
           <tr>
              <td> Cristian Gonzalo Vera </td>
              <td> Gona79 </td>
              <td>
                <a href="https://github.com/Gona79">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
        </table>
  </dd>
  <dd>
<dl>

<br>

<h1> 👩‍💻👨🏼‍💻 Integrantes 👩‍💻👨🏼‍💻 </h1>
        <table align="center">
          <thead>
            <tr>
              <th>Nombre y Apellido</th>
              <th>Usuario en GitHub</th>
              <th>GitHub</th>
            </tr>
          </thead>
          <tbody>
            <tr>
              <td> Leandro Roldan </td>
              <td> pleroldan </td>
              <td>
                <a href="https://github.com/pleroldan">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
            <tr>
              <td> Fernando Gimenez Coria </td>
              <td> FerCbr </td>
              <td>
                <a href="https://github.com/FerCbr">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
            <tr>
              <td> Karina jazmin barbero </td>
              <td> karina-lolis </td>
              <td>
                <a href="https://github.com/karina-lolis">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
            <tr>
              <td> Nicolás Nahuel Barrionuevo </td>
              <td> NicolasBa27 </td>
              <td>
                <a href="https://github.com/NicolasBa27">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
            <tr>
              <td> Macarena Aylen Carballo </td>
              <td> MacarenaAC </td>
              <td>
                <a href="https://github.com/MacarenaAC">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
           <tr>
              <td> Raul Jara </td>
              <td> r-j28 </td>
              <td>
                <a href="https://github.com/r-j28">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
           <tr>
              <td> Diego Ezequiel Ares </td>
              <td>  diegote7 </td>
              <td>
                <a href="https://github.com/diegote7">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
           <tr>
              <td> Romina Huk </td>
              <td> RoHu17 </td>
              <td>
                <a href="https://github.com/RoHu17">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
            <tr>
              <td> Paola Pantoja </td>
              <td> - </td>
              <td>
                <a href="https://github.com/PaolaaPantoja">
                  <img src="https://img.shields.io/badge/github-%23121011.svg?&style=for-the-badge&logo=github&logoColor=white"/>
                </a>
              </td>
            </tr>
        </table>
  </dd>
  <dd>
<dl>


### Sistema IoT para el Monitoreo de Calidad del Aire.

### Descripción del Proyecto:

- Este repositorio contiene la documentación y el código fuente para el prototipo de un dispositivo IoT diseñado para el monitoreo continuo de la calidad del aire en ambientes inmóticos. El objetivo de este prototipo es probar la funcionalidad básica del dispositivo, incluyendo la captura de datos, procesamiento inicial, y transmisión segura a una plataforma en la nube. Se busca identificar patrones en los niveles de contaminantes y otros factores que afectan la calidad del aire para permitir la toma de decisiones informadas y la activación de sistemas de respuesta automática.

## **Estructura del Prototipo**
### **Equipo**
   
- **Componentes principales:**

- Sensores Ambientales: Se utilizarán sensores de temperatura, humedad, calidad del aire (CO2, PM2.5, PM10), y niveles de luz. Estos sensores capturan datos en tiempo real y los envían al microcontrolador.
- Microcontrolador: El ESP32 WROOM, equipado con módulos de conectividad Wi-Fi y Bluetooth, y la posibilidad de integrar un módulo LoRa para comunicaciones de largo alcance, actuará como el núcleo de procesamiento en la capa EDGE. Este microcontrolador maneja la comunicación con los sensores ambientales.
- Batería: Se empleará una batería LiPo de 3.7V 1000mAh (mínimo) recargable para asegurar la operación continua del dispositivo durante períodos prolongados.
- Carcasa: Se diseñará una carcasa a medida, posiblemente fabricada con una impresora 3D, para alojar el hardware del prototipo.

### **Software**
   
- **Módulos principales:**

- Captura de Datos: Código para la inicialización y adquisición de datos de los sensores ambientales. La comunicación con los sensores se manejará a través de - protocolos I2C/SPI.
- Procesamiento Inicial: Algoritmos implementados en el microcontrolador para el filtrado de datos, eliminación de ruido, y normalización de los valores capturados.
- Transmisión de Datos: Código para la transmisión de los datos preprocesados a la nube utilizando protocolos MQTT o HTTP sobre Wi-Fi/Bluetooth/LoRaWAN.
- Gestión de Energía: Implementación de rutinas de bajo consumo para maximizar la duración de la batería.
- Interfaz de Usuario: Una sencilla interfaz LCD o LED que mostrará el estado del dispositivo y los niveles de calidad del aire en tiempo real.

### **Conectividad**
   

- **Redes soportadas:**

- Wi-Fi: El dispositivo se conectará a redes Wi-Fi para transmitir datos directamente a la nube.
- Bluetooth: Soporte para conectividad Bluetooth, permitiendo la sincronización con una aplicación móvil cercana.

- **Protocolos Utilizados:**

- MQTT: Protocolo de mensajería ligero utilizado para la transmisión de datos a la plataforma en la nube.
- HTTP/HTTPS: Utilizado para la comunicación segura con servidores web y APIs.

### **Plataforma en la Nube**
   

- **Servicios sugeridos a utilizar:**

- AWS IoT Core / Azure IoT Hub: Para la gestión de dispositivos y la recolección de datos en tiempo real.
- Base de Datos NoSQL: Almacenamiento de datos en una base de datos NoSQL para un acceso rápido y eficiente.
- Dashboard de Monitoreo: Una interfaz web sencilla que permitirá la visualización en tiempo real de los datos de calidad del aire transmitidos por el dispositivo.

### **Pruebas y Validación**
   

- **Pruebas realizadas:**

- Pruebas de Conectividad: Verificación de la conexión Wi-Fi y Bluetooth en diferentes entornos.
- Pruebas de Precisión: Comparación de las lecturas de los sensores con equipos de monitoreo de calidad del aire estándar para validar la precisión.
- Pruebas de Durabilidad: Evaluación de la duración de la batería bajo uso continuo.

### **Instrucciones de Configuración**
   

- **Requisitos previos:**

- Instalar Visual Studio Code con la extensión de PlatformIO para la programación del ESP32 WROOM.
- Clonar este repositorio y abrir el proyecto en VSCode.

- **Pasos para la Configuración:**

- Conectar los Sensores: Conecte los sensores ambientales al ESP32 WROOM según el esquema de pines proporcionado en la carpeta hardware.
- Cargar el Código: Compilar y cargar el código fuente en el ESP32 WROOM utilizando PlatformIO.
- Configurar la Red: Configurar los parámetros de red (SSID, contraseña) en el archivo config.h.
- Ejecutar el Prototipo: Encender el dispositivo y verificar que los datos se transmiten correctamente a la nube.

### **Futuras Mejoras**
   

- Optimización del Consumo de Energía: Mejorar las rutinas de gestión de energía para extender la duración de la batería.
- Mejoras en la Interfaz de Usuario: Desarrollar una interfaz gráfica más avanzada en la aplicación móvil para la visualización de datos.
- Integración con AI: Implementar análisis predictivo utilizando aprendizaje automático en la nube para detectar patrones en la calidad del aire.


**Licencia**
Este proyecto está bajo la licencia ISPC. Consulta el archivo LICENSE para más detalles.
