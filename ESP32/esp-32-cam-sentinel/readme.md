# esp32-cam sentinel

Proyecto para utilizar sensores MLX90614 , detectores de presencia y cámara integrada.

## Disclaimer

* Este proyecto no ofrece garantía alguna de fiabilidad, seguridad para su uso en escenarios reales
* No tiene ningún ánimo comercial.
* Se trata de un trabajo exclusivamente académico, no lo uses en tu casa !!

## Objetivo

Este proyecto tiene como objetivo correlacionar hasta tres fuentes de sensorización:

* Temperatura de una zona , con sensores MLX90614. Se utilizarán dos sensores del mismo tipo para reforzar la selección
* Presencia en una zona, con sensores de detección de presencia.
* Imagen de una zona, mediante la cámara del ESP32, para poder procesarla posteriormente.

Con las 3 fuentes se pretende construir una máquina de estados que nos indicará las siguientes cuestiones:
 * Si la zona tiene fuentes de calor
 * Si hay alguien en la zona
 * Si los accionadores de las fuentes de calor están activados o no

## Arquitectura

La arquitectura dispone de varios módulos, que a medida que se añadan aumentarán la potencia de la solución. El siguiente esquema muestra el diseño inicial:

```text
    m1                                                        m2

+--------+                                                +--------+
| ESP-32 + -------- <MLX90614 _1>      ))) wifi (((       | ESP-32 + -------- <Detector presencia>
|        + -------- <MLX90614 _2>                         |  CAM   + -------- <Cámara>
+--------+                                                +--------+
```


Los dos módulos se conectan por wifi a través de una red propia, el servidor lo genera m2 y m1 será un cliente  

* m1 : Módulo WifClient, lógica de procesamiento de señales locales, escalvo de m2 para ejecutar comandos
* m2 : Módulo AccesPoint, Servidor Web , Api Rest, lógica de procesamiento de las señales locales ,master de control sobre m1

## Principio de funcionamiento

La unidad m1 recibe y ejecuta órdenes de procesamiento del la unidad m2, esencialmente monitorizar las medidas que ofrecen los sensores, dispone de una pequeña máquina de estados, que puede
enviar peticiones a la unidad de m2 ante determinados eventos
La unidad m2 contiene la lógica completa, ante señalesm /datos provenientes del sensor de presencia o datos de la unidad m2, captura la zona con la cámara

En la fase inicial , todo se mostrará a partir de una pagina visualizable en un dispositivo móvil que se encuentre en la red  
Posteriormente, con conexión internet, se podrán enviar alarmas.
    
