# Comunicación serie bidireccional entre Arduino Uno R3

Proyecto que establece una comunicación bidireccional serie entre dos placas arduino 

## Fundamentos

Cada placa utiliza una UART virtual para comunicarse con la otra.
En este ejemplo se establece el enlace entre una placa BLACK y una placa BLUE
No hay procesamiento de mensajes, simplemente se envían a la consola.

IMPORTANTE : Al tratarse de UART virtuales la velocidad de transferencia se ha limitado a 9600 bps

## Archivos
 Se sumninistran dos archivos .ino, :

 * Black.ino, código para la primera placa
 * Blue.ino, código para la segunda placa
