from picozero import LED, Button
# Configuración: LED interno y botón en pin 15
led = LED(19)
led2 = LED(20)
# inicializar estado de los led
led.off()
led2.on()
# instanciar el botón ( por defecto está en pullUp)
boton = Button(15)
# función que se ejecutará cuando se generen los eventos del botón
def p():
    led.toggle()    # Invierte el estado del led on->off ó off->on
    led2.toggle()
# Al presionar, invoca a la función de call_back que definamos
# Importante: se pasa el nombre de la función sin paréntesis
boton.when_pressed = p
# En raspi no hace falta dejar el bucle, esto se ejecuta hasta que se mata.
