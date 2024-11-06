from gpiozero import Button
from gpiozero import LED
from time import sleep
#from 라이브러리 import 클래스

ledRed = LED(23) #23핀을 LED로, ledRed에 할당하고 초기화
ledBlue = LED(24)
swPin = Button(21) #21핀 버튼으로 swPin에 초기화

swState = 0 #현재 상태를 저장하기 위한 변수 초기화

try:
    while 1: #무한루프
        swValue = swPin.is_pressed #핀 상태 확인, swValue 변수에 저장
        if swValue == True: #swPin.is_pressed 의 값은 T/F 로 나옴
            if swState == 0: #True이고(버튼이눌렸고) 기존 상태가 0이면
                swState = 1 #1저장
            else:
                swState = 0 #기존 상태가 1이면 0으로 저장, 여기가
            sleep(0.5) #헷갈릴 수 있는 부분!
#sleep 타임을 1초로 하면 꾹- 눌러야 바뀌는 설정도 가능하다.
        print(swState)
        sleep(1.0)

except KeyboardInterrupt:
    pass