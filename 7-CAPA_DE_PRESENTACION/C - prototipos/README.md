# Plataforma IoT para Monitoreo de Calidad del Aire

## Descripción

La **Plataforma IoT para Monitoreo de Calidad del Aire** es una aplicación web diseñada para monitorear y visualizar datos sobre la calidad del aire. A través de esta plataforma, los usuarios pueden obtener información en tiempo real sobre la calidad del aire, gestionar sus perfiles y administrar los dispositivos conectados.

## Estructura del Proyecto

```bash
├── /assets/              # Archivos multimedia como imágenes y logotipos
├── /css/                 # Archivos de estilos (CSS)
├── /docs/                # Documentación del proyecto
├── /js/                  # Archivos de JavaScript
├── /admin_panel.html     # Página del panel de administración
├── /index.html           # Página principal de la plataforma
├── /login.html           # Página de inicio de sesión
├── /nosotrosAbout.html   # Página sobre el equipo
├── /perfilUser.html      # Página de perfil de usuario
├── /user_panel.html      # Página del panel del usuario
└── README.md             # Archivo README con la documentación del proyecto

```

### Descripción de las Páginas HTML  

**admin_panel.html:** Página del panel de administración donde los administradores pueden gestionar usuarios, dispositivos y configuraciones del sistema.  

**index.html:** Página principal de la plataforma, que sirve como el punto de entrada para los usuarios.  

**login.html:** Página de inicio de sesión para los usuarios registrados.  

**nosotrosAbout.html:** Página que proporciona información sobre el equipo de desarrollo y la misión del proyecto.  

**perfilUser.html:** Página donde los usuarios pueden visualizar y modificar sus perfiles personales, como nombre, correo y configuraciones.  

**user_panel.html:** Panel donde los usuarios pueden ver los datos recolectados por sus dispositivos conectados y realizar acciones como generar reportes o configurar alertas.  

### Tecnologías Utilizadas
Frontend: HTML5, CSS3, JavaScript.
Backend: Python con Flask (API RESTful).
Base de Datos: MySQL.
Microcontroladores IoT: ESP32 con sensores (MQ135, AHT25, BMP280, etc).
Servidor: Ubuntu con Apache, integrando servicios y APIs para la recolección y análisis de datos.