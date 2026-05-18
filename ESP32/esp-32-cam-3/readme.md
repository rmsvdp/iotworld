# Enlace serie entre ESP32 y Arduino Uno R3

Este proyecto implementa un enlace de bajo nivel entre un arduino uno R3 y el módulo ESP32CAM
Se acompañan una sección de test entre dos arduinos.

## fundamentos

Se establece un enlace físico entre las uarts de ambos equipos. En el caso de ESP32 es preciso a nivel
de circuito electronico efectuar una adaptación de niveles. Existen dos alternativas:

1. Adaptación mediante divisor de tensión (TX1)--[ 1K ]---+(RX1)+--[ 2K ]--<GND>
2. Circuito conversor de nivel ( uni / bi ) direccional

En este proyecto se utiliza la opción 1, porque el enlace es unidireccional. Tensión en TX1 = 5V, Tensión en RX1 = 3,3V

