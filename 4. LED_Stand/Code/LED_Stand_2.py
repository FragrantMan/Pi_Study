from gpiozero import PWMLED, Button
from time import sleep

led_white = PWMLED(12)
swPin = Button(21)

swState = 0

newSw = 0
oldSw = 0

def swOn():
    global newSw
    global oldSw
    newSw = swPin.is_pressed

    if newSw != oldSw:
        oldSw = newSw
        if newSw == 1:
            return 1
    
    return 0


try:
    while True:
        if swOn() == 1:
            swState = swState+1
            if swState >= 4:
                swState = 0
            sleep(0.2)

            print(swState)

            if swState == 0:
                led_white.value = 0
                print(" duty:0 ")
            elif swState == 1:
                led_white.value = 0.3
                print(" duty:30 ")
            elif swState == 2:
                led_white.value = 0.6
                print(" duty:60 ")
            elif swState == 3:
                led_white.value = 1
                print(" duty:100 ")

except KeyboardInterrupt:
        pass

led_white.value = 0
