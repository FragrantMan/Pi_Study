from gpiozero import Button
from gpiozero import LED
from time import sleep

ledRed = LED(23)
ledBlue = LED(24)
swPin = Button(21)

swState = 0

try:
    while 1:
        swValue = swPin.is_pressed #swValue에 입력값 저장
        if swValue == True: #만약 눌렸는데
            if swState == 0: #만약 상태가 0 이었으면
                swState = 1 #1로 바꿔주고
            else:
                swState = 0 #그밖에 나머지 = 1이었으면 0으로
            sleep(0.5) #입력에 따라 on off 를 1과 0 으로 만든 것

        if swState == 1: #켜졌으면 번쩍번쩍
            ledRed.on()
            ledBlue.off()
            sleep(0.1)
            ledRed.off()
            ledBlue.on()
            sleep(0.1)
        else:
            ledRed.off()
            ledBlue.off()
except KeyboardInterrupt:
    pass

ledRed.off()
ledBlue.off()