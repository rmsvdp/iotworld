from picozero import LED, Button


# Configuración: LED interno y botón en pin 15
led = LED(19)
led2 = LED(20)

led.off()
led2.on()

boton = Button(15)

def p():
    led.toggle()
    led2.toggle()
# Al presionar, se ejecuta el método toggle (invertir)
# Importante: se pasa el nombre de la función sin paréntesis
boton.when_pressed = p
