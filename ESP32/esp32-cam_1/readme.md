# esp32-cam_1

Proyecto que implementa en el módulo ESP32 
Los objetivos de este proyecto son :
1. Implementar un servidor web muy básico con varios end-point
2. incorporar código de cliente con javascript
3. Endpoint en los dos sentidos : consulta ( datos de un canal) y escritura (actuación sobre el microcontrolador)
4. Utilización del protocolo MQTT con conexión a servidor mosquitto

### Fundamentos

El código que corre en el microcontrolador implementa un servidor web y lo enlaza con funciones de bajo nivel
que enlazan con el dispositivo y también con servidores MQTT

