from gpiozero import Button
from gpiozero import LED
from time import sleep
#from 라이브러리 import 클래스

ledRed = LED(23) #23핀을 LED로, ledRed에 할당하고 초기화
ledBlue = LED(24)
swPin = Button(21)

try:
    while 1: #무한루프
        swValue = swPin.is_pressed #핀 상태 확인, swValue 변수에 저장
        print(swValue) #버튼 상태 출력
        sleep(0.1)
except KeyboardInterrupt:
    pass