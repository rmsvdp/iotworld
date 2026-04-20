
# Arquitectura

# Servidores Node-Red y Mosquito

Implementados con Docker

# Software en ESP-32

## Liberías necesarias  

1.- Incorporar librerías desde fuentes

 	1a descargar el código de github como zip (code -> zip ):
 
	> https://github.com/me-no-dev/ESPAsyncWebServer
	> https://github.com/me-no-dev/AsyncTCP
 
	 2a incorporar liberías al IDE

 2.- Cliente MQTT para ESP32

     ** Se busca PubSubClient entre las oficiales y se instala

## Fundamentos

* ESPAsyncWebServer es un servidor web ligero y asíncrono (consume mucho menos que el tradicional)
* Esta elección libera el loop() para otras tareas, como la de cliente MQTT
* PubSubClient permite suscribrirse para leer/escribir en un broker mqtt

## Publicación Web

* Utilizamos Ajax ( con javascript ) para hacer más responsive la página
* Generamos los métodos ( enpoints) en el ESP32, no son REST-FULL

## Mejoras

* Añadir API-REST estrictas (payload Json y métodos GET/PUT/DELETE)

# Referencias utilizadas

### DIDACTRONICA

https://didactronica.microlsb.es/docs-category/comequipos

https://didactronica.microlsb.es/docs/esp32-con-siemens-por-node-red-con-mqtt-preconfigurado

### HUECAT

https://huecat.es/esp8266-and-node-red-with-mqtt-publish-and-subscribe/

### MEDIATECA

https://mediateca.educa.madrid.org/video/lmd7wn5dj4w7nqvs

### LUIS LLAMAS

https://www.luisllamas.es/curso-mqtt/
https://www.luisllamas.es/curso-esp8266-esp32/
https://www.luisllamas.es/enviar-y-recibir-mensajes-por-mqtt-con-arduino-y-la-libreria-pubsubclient/
