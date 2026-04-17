# Librería para tiras de led genericas (neopixel)
# https://github.com/blaz-r/pi_pico_neopixel.git
import time
from neopixel import Neopixel

numpix = 32
strip = Neopixel(numpix, 0, 0, "GRB")  # Ojo a esta codificación
strip.brightness(20)                   # intensidad en pixels
# Construir máscara : R, G , B !!
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)
# Todos azules
strip[:] = red   # all to blue first...
#Mostrar
strip.show()
