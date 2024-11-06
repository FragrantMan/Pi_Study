from gpiozero import MCP3208
import time

cds = MCP3208(channel = 0) #1번핀에 10k옴 저항 연결인데. 1번핀이 0채널임
try:
    while 1:
        cds_value = cds.value * 100 #0~100으로 바꿔주는 함수
        print(cds_value)
        time.sleep(0.2)

except KeyboardInterrupt:
    pass