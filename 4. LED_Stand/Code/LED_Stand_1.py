from gpiozero import PWMLED
from time import sleep

led_white = PWMLED(12)

try:
    while True:
        led_white.value = 0
        print(" duty:0 ")
        sleep(2)
        led_white.value = 0.3
        print(" duty:30 ")
        sleep(2)
        led_white.value = 0.6
        print(" duty:60 ")
        sleep(2)
        led_white.value = 1
        print(" duty:100 ")
        sleep(2)

except KeyboardInterrupt:
    pass

led_white.value = 0
