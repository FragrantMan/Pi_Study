#include <wiringPi.h>
#include <iostream>
#include <unistd.h>

#define LED_WHITE 12
#define BUTTON_PIN 21

int main() {
    // GPIO 초기화
    wiringPiSetupGpio();

    // 핀 모드 설정
    pinMode(LED_WHITE, PWM_OUTPUT);
    pinMode(BUTTON_PIN, INPUT);

    int swState = 0;
    int newSw = 0;
    int oldSw = 0;

    // 메인 루프
    while (true) {
        newSw = digitalRead(BUTTON_PIN); // C++에서는 is_pressed와 같은 직접적인 메서드는 없음

        // 버튼 상태가 변했을 때
        if (newSw != oldSw) {
            oldSw = newSw;
            if (newSw == HIGH) { // 버튼이 눌렸을 때
                swState++;
                if (swState >= 4) {
                    swState = 0;
                }
                usleep(200000); // 0.2초 대기

                std::cout << "State: " << swState << std::endl;
                //state라는 문자와 변수 swState를 내기 위한 형식
                //구분을 << 로 하는 것. 줄 바꿈은 \n 도 되지만
                //std::endl; 이 출력 버퍼를 비워서 더 빠르다.

                // LED 밝기 조절
                if (swState == 0) {
                    pwmWrite(LED_WHITE, 0); // duty cycle 0%
                    std::cout << "duty: 0" << std::endl;
                } else if (swState == 1) {
                    pwmWrite(LED_WHITE, 77); // duty cycle 30%
                    std::cout << "duty: 30" << std::endl;
                } else if (swState == 2) {
                    pwmWrite(LED_WHITE, 153); // duty cycle 60%
                    std::cout << "duty: 60" << std::endl;
                } else if (swState == 3) {
                    pwmWrite(LED_WHITE, 255); // duty cycle 100%
                    std::cout << "duty: 100" << std::endl;
                }
            }
        }
        usleep(10000); // debounce delay
    }

    // 프로그램 종료 시 LED 끄기
    pwmWrite(LED_WHITE, 0);

    return 0;
}
