# Informe de Cambios Realizados

Este informe documenta los cambios realizados en la implementación del código JavaScript utilizado para interactuar con una API de monitoreo de calidad de aire, gestionar la autenticación de usuarios, y configurar alertas. Las mejoras incluyen la autenticación mediante API, la obtención de datos del sensor, y la configuración de umbrales de alertas, entre otras funciones adicionales.


#### 1. **Autenticación de Usuarios (Función `login`)**
- Se agregó una función de autenticación que permite a los usuarios iniciar sesión en la plataforma utilizando un email y contraseña.
- **Flujo**: 
  - Se realiza una solicitud POST a la API para verificar las credenciales del usuario.
  - Si la autenticación es exitosa, el token de acceso se almacena en `localStorage` para futuras solicitudes.
  - En caso de error, se muestra un mensaje informando al usuario.

#### 2. **Verificación de Acceso a Páginas Protegidas (Función `checkProtectedPage`)**
- Se implementó un mecanismo para verificar si un usuario ha iniciado sesión antes de acceder a una página protegida.
- Si el token de acceso no está presente o es inválido, el usuario es redirigido a la página de inicio de sesión.

#### 3. **Obtención de Datos del Sensor (Función `fetchSensorData`)**
- Se implementó la función para obtener datos de los sensores conectados al dispositivo con ID 2.
- Los valores de concentración de gases (`aqi`), presión, temperatura, humedad, luz, y radiación UV se muestran en tiempo real en la interfaz de usuario.
- **Mejora**: Se manejan los errores en la obtención de datos, proporcionando un mensaje de error en la consola si algo falla.

#### 4. **Carga de Datos de Sensores Específicos (Función `cargarDatosSensores`)**
- Función adicional que carga los datos de sensores específicos, como el sensor MQ135, UV, y luz ambiental, y los asigna a sus respectivos elementos en la página.
- **Mejora**: Se añadieron mensajes de error detallados en caso de problemas de conexión o errores en el servidor.

#### 5. **Configuración de Alertas (Función `setAlertConfig`)**
- Se añadió una función para que los usuarios configuren umbrales de alertas personalizadas basadas en la calidad del aire.
  - Umbrales como `aqi`, temperatura, y humedad se pueden ajustar y enviar al servidor.
- Los valores son enviados mediante una solicitud POST a la API, y los umbrales son guardados correctamente con una retroalimentación visual para el usuario.

#### 6. **Configuración de Umbrales en la Interfaz de Usuario (Función `configurarAlertas`)**
- Se añadió un formulario en la interfaz para que el usuario pueda ajustar los umbrales de alertas de PM2.5 y CO2.
  - Los valores se almacenan en `localStorage` y se ofrece retroalimentación visual mediante cambios en el texto y color del botón de guardar.

#### 7. **Eventos en la Sección del Equipo (Función `agregarEventosEquipo`)**
- Se añadieron eventos de interacción a la sección del equipo, de forma que al hacer clic en un miembro del equipo, se muestra un mensaje con la información del miembro seleccionado.

### Funcionalidades Clave Agregadas

- **Autenticación**: Permite iniciar sesión y proteger páginas con tokens de acceso.
- **Visualización en tiempo real**: Obtención y visualización de datos del sensor de calidad de aire.
- **Configuración de alertas**: Personalización de umbrales de calidad del aire, con guardado de configuraciones y retroalimentación visual.
- **Interacción con el equipo**: Mejora en la interacción visual con los miembros del equipo.

### Recomendaciones para el Uso
1. **Autenticación**: Antes de acceder a páginas protegidas, los usuarios deben iniciar sesión. Si el token expira o es inválido, el sistema redirige automáticamente al usuario a la página de inicio de sesión.
2. **Datos del sensor**: La visualización de datos está integrada en el `DOMContentLoaded`, por lo que se cargan automáticamente al cargar la página.
3. **Configuración de alertas**: Los umbrales deben ser establecidos en el formulario de alertas, los valores se guardan y envían al servidor para el monitoreo continuo.
