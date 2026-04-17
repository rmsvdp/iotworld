# myIOTSys

Entorno dockerizado con node red

## Descripción

Este stack lanza dos servidores :

- nodeRed
- mosquitto server

## Ejemplo de uso

El stack ya viene con una configuración de test:

* Mosquitto está registrado en node-red
* se ha creado un flujo que genera aleatoriamente un dato y lo inyecta al bus MQTT
* En modo depuración se recogen los datos y se presentan (abrir ventana dcha si no aparece)