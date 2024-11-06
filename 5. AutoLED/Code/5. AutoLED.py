from gpiozero import LED, MCP3208
import time

led_White = LED(18)
cds = MCP3208(channel = 0) #1번핀에 10k옴 저항 연결인데. 1번핀이 0채널임

try:
    while 1:
        cds_value = cds.value * 100 #0~100으로 바꿔주는 함수
        print(cds_value)

        if cds_value < 50: led_White.on()#조도센서 값이 50보다 작으면 켜라
        else: led_White.off() 

        time.sleep(0.2)

except KeyboardInterrupt:
    pass

led_White.off()