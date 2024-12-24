![logo_ispc](../E%20assets/logoISPC.png)   

# Migración de la API desarrollada con Flask a FastAPI    


## Migración de app.py  


## **Código Flask:**  

``` python

from flask import Flask, request, jsonify
from db_config import close_db_connection
from routes.configuraciones import configuraciones_bp
from routes.datos_dispositivos import datos_dispositivos_bp
from routes.dispositivos import dispositivos_bp
from routes.proyectos import proyectos_bp
from routes.seguridad import seguridad_bp
from routes.usuarios import usuarios_bp

app = Flask(__name__)

# Middleware para verificar la clave de API
@app.before_request
def before_request():
    api_key = request.headers.get('X-API-KEY')
    if not api_key or api_key not in ['jade', 'opalo', 'rubi', 'topaz', 'plata']:  # Claves de API válidas
        return jsonify({'error': 'Unauthorized access'}), 401

# Registro de Blueprints
app.register_blueprint(configuraciones_bp, url_prefix='/configuraciones')
app.register_blueprint(datos_dispositivos_bp, url_prefix='/datos_dispositivos')
app.register_blueprint(dispositivos_bp, url_prefix='/dispositivos')
app.register_blueprint(proyectos_bp, url_prefix='/proyectos')
app.register_blueprint(seguridad_bp, url_prefix='/seguridad')
app.register_blueprint(usuarios_bp, url_prefix='/usuarios')

app.teardown_appcontext(close_db_connection)

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
```



## **Código FastAPI:** 
```python

from fastapi import FastAPI, Request, HTTPException
from fastapi.responses import JSONResponse
from db_config import close_db_connection
from routes.configuraciones import configuraciones_router
from routes.datos_dispositivos import datos_dispositivos_router
from routes.dispositivos import dispositivos_router
from routes.proyectos import proyectos_router
from routes.seguridad import seguridad_router
from routes.usuarios import usuarios_router

app = FastAPI()

# Middleware para verificar la clave de API
@app.middleware("http")
async def verify_api_key(request: Request, call_next):
    api_key = request.headers.get('X-API-KEY')
    if not api_key or api_key not in ['jade', 'opalo', 'rubi', 'topaz', 'plata']:  # Claves de API válidas
        return JSONResponse(status_code=401, content={"error": "Unauthorized access"})
    response = await call_next(request)
    return response

# Registro de routers
app.include_router(configuraciones_router, prefix='/configuraciones')
app.include_router(datos_dispositivos_router, prefix='/datos_dispositivos')
app.include_router(dispositivos_router, prefix='/dispositivos')
app.include_router(proyectos_router, prefix='/proyectos')
app.include_router(seguridad_router, prefix='/seguridad')
app.include_router(usuarios_router, prefix='/usuarios')

@app.on_event("shutdown")
def shutdown_event():
    close_db_connection()

if __name__ == '__main__':
    import uvicorn
    uvicorn.run(app, host='0.0.0.0', port=5000)  

```        


# Notas sobre la migración:  

- **Middleware:** FastAPI utiliza una función decorada con @app.middleware("http") en lugar de @app.before_request.  

- **Routers:** En FastAPI, los Blueprints se convierten en Routers y se registran con app.include_router.  

- **Teardown:** FastAPI usa eventos como @app.on_event("shutdown") para cerrar conexiones.   


## Ahora migremos los endpoints. Tomaremos el archivo usuarios.py como ejemplo:  

## **Código Flask:**  

```python

from flask import Blueprint, request, jsonify
from db_config import get_db_connection

usuarios_bp = Blueprint('usuarios', __name__)

@usuarios_bp.route('/', methods=['GET'])
def get_usuarios():
    conn = get_db_connection()
    cursor = conn.cursor(dictionary=True)
    cursor.execute("SELECT * FROM Usuarios")
    usuarios = cursor.fetchall()
    cursor.close()
    return jsonify(usuarios)

@usuarios_bp.route('/<int:id>', methods=['GET'])
def get_usuario(id):
    conn = get_db_connection()
    cursor = conn.cursor(dictionary=True)
    cursor.execute("SELECT * FROM Usuarios WHERE id_usuario = %s", (id,))
    usuario = cursor.fetchone()
    cursor.close()
    return jsonify(usuario)

@usuarios_bp.route('/', methods=['POST'])
def add_usuario():
    nuevo_usuario = request.json
    conn = get_db_connection()
    cursor = conn.cursor()
    cursor.execute(
        "INSERT INTO Usuarios (nombre, email, rol, password_hash) VALUES (%s, %s, %s, %s)",
        (nuevo_usuario['nombre'], nuevo_usuario['email'], nuevo_usuario['rol'], nuevo_usuario['password_hash'])
    )
    conn.commit()
    cursor.close()
    return '', 201

@usuarios_bp.route('/<int:id>', methods=['PUT'])
def update_usuario(id):
    usuario_actualizado = request.json
    conn = get_db_connection()
    cursor = conn.cursor()
    cursor.execute(
        "UPDATE Usuarios SET nombre = %s, email = %s, rol = %s, password_hash = %s WHERE id_usuario = %s",
        (usuario_actualizado['nombre'], usuario_actualizado['email'], usuario_actualizado['rol'], usuario_actualizado['password_hash'], id)
    )
    conn.commit()
    cursor.close()
    return '', 204

@usuarios_bp.route('/<int:id>', methods=['DELETE'])
def delete_usuario(id):
    conn = get_db_connection()
    cursor = conn.cursor()
    cursor.execute("DELETE FROM Usuarios WHERE id_usuario = %s", (id,))
    conn.commit()
    cursor.close()
    return '', 204
```

## **Código FastAPI:**
```python

from fastapi import APIRouter, HTTPException, Request
from pydantic import BaseModel
from db_config import get_db_connection

usuarios_router = APIRouter()

class Usuario(BaseModel):
    nombre: str
    email: str
    rol: str
    password_hash: str

@usuarios_router.get('/')
async def get_usuarios():
    conn = get_db_connection()
    cursor = conn.cursor(dictionary=True)
    cursor.execute("SELECT * FROM Usuarios")
    usuarios = cursor.fetchall()
    cursor.close()
    return usuarios

@usuarios_router.get('/{id}')
async def get_usuario(id: int):
    conn = get_db_connection()
    cursor = conn.cursor(dictionary=True)
    cursor.execute("SELECT * FROM Usuarios WHERE id_usuario = %s", (id,))
    usuario = cursor.fetchone()
    cursor.close()
    if not usuario:
        raise HTTPException(status_code=404, detail="Usuario no encontrado")
    return usuario

@usuarios_router.post('/', status_code=201)
async def add_usuario(usuario: Usuario):
    conn = get_db_connection()
    cursor = conn.cursor()
    cursor.execute(
        "INSERT INTO Usuarios (nombre, email, rol, password_hash) VALUES (%s, %s, %s, %s)",
        (usuario.nombre, usuario.email, usuario.rol, usuario.password_hash)
    )
    conn.commit()
    cursor.close()
    return {}

@usuarios_router.put('/{id}', status_code=204)
async def update_usuario(id: int, usuario: Usuario):
    conn = get_db_connection()
    cursor = conn.cursor()
    cursor.execute(
        "UPDATE Usuarios SET nombre = %s, email = %s, rol = %s, password_hash = %s WHERE id_usuario = %s",
        (usuario.nombre, usuario.email, usuario.rol, usuario.password_hash, id)
    )
    conn.commit()
    cursor.close()
    return {}

@usuarios_router.delete('/{id}', status_code=204)
async def delete_usuario(id: int):
    conn = get_db_connection()
    cursor = conn.cursor()
    cursor.execute("DELETE FROM Usuarios WHERE id_usuario = %s", (id,))
    conn.commit()
    cursor.close()
    return {}
```

## Notas sobre la migración:
- **Esquemas Pydantic:** FastAPI utiliza Pydantic para la validación de datos. Creamos un modelo Usuario para las solicitudes POST y PUT.  

- **Funciones asincrónicas:** FastAPI soporta funciones asincrónicas, aunque también puedes usar funciones sincrónicas.  

- **Manejo de errores:** Utilizamos HTTPException para manejar errores y devolver códigos de estado adecuados.  

- **Decoradores de rutas:** Las rutas en FastAPI usan @router.<method> en lugar de @blueprint.route.  

Con esta estructura, se puede migrar el resto de los archivos de rutas.   

    
# Mejore su netWorking

Si quiere mejorar su networking puede investigar sobre los temas que se mencionan en el documento pdf: Anexo a Unidad 3, y completar su investigacion aca.