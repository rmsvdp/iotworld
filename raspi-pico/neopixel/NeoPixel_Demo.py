import time
from neopixel import Neopixel

numpix = 5
# El pin es lógico, es decir 15 hace referencia
# al GPIO15, que está en el pin 20 de la placa
strip = Neopixel(numpix, 0, 15, "RGB")

red = (255, 0, 0)
orange = (255, 165, 0)
yellow = (255, 150, 0)
green = (0, 255, 0)
blue = (0, 0, 255)
indigo = (75, 0, 130)
violet = (138, 43, 226)
colors_rgb = (red, orange, yellow, green, blue, indigo, violet)

# uncomment colors_rgb if you have RGB strip
colors = colors_rgb
#colors = colors_rgbw

strip.brightness(42)

while True:
    for color in colors:
        for i in range(numpix):
            strip.set_pixel(i, color)
            time.sleep(0.05)
            strip.show()