from gpiozero import MCP3208 #MCP3208 모듈 사용
import time

gas = MCP3208(channel = 0) #1번 채널 = 0, 읽어서 gas 에 저장

try:
    while 1:
        gasValue = gas.value *100 # 소수점인 값을 데이터 파싱
        print(gasValue)

        time.sleep(0.2)

except KeyboardInterrupt:
    pass