# Core para Player archivos mp3

En este proyecto utilizaremos el módulo ESP32-CAM como player de archivos MP3, para ello se utilizar el módulo
DFPlayerMini, que es una solución hardware

## Fundamentos

El módulo DFPlayerMini contiene un lector de tarjetas microSD y la electrónica para reproducir archivos mp3.
Se necesita una la libería específica : 

## Esquema

El módulo ESP32 utilizar los pines 14 y 15 para las señales RX/TX que gobiernan el DFPlayer a través de la 
uart 2 (usada por el lector SD integrado del ESP32-CAM. pero como no lo utilizamos se pueden reaprovechar)
