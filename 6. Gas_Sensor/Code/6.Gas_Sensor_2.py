from gpiozero import Buzzer, MCP3208
import time

bz = Buzzer(18)
gas = MCP3208(channel = 0)

try:
    while 1:
        gasValue= gas.value*100
        print(gasValue)
        if gasValue >= 50: #기본 값들이 25 이렇게 나와고
            bz.on() #라이터 가져가면 50까지 빠르게 넘어가서 50 설정
        else:
            bz.off()
        
        time.sleep(0.2)

except KeyboardInterrupt:
    pass

bz.off()