#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //파이썬에 비해 헤더파일 선언할게 많다.

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
    while (1) {
        newSw = digitalRead(BUTTON_PIN);//파이썬은 is_pressed

        // 버튼 상태가 변했을 때
        if (newSw != oldSw) {
            oldSw = newSw;
            if (newSw == HIGH) { // 버튼이 눌렸을 때
                swState++; //파이썬은 a = a+1 로 해줌.
                if (swState >= 4) {
                    swState = 0;
                }
                usleep(200000); // 0.2초 대기, c는 1초 이하의 시간은 usleep

                printf("State: %d\n", swState);

                // LED 밝기 조절
                if (swState == 0) { //파이썬은 괄호,중괄호가 적고 :로 간단하다.
                    pwmWrite(LED_WHITE, 0); // duty cycle 0%
                    printf("duty: 0\n");
                } else if (swState == 1) {
                    pwmWrite(LED_WHITE, 77); // duty cycle 30%
                    printf("duty: 30\n");
                } else if (swState == 2) {
                    pwmWrite(LED_WHITE, 153); // duty cycle 60%
                    printf("duty: 60\n");
                } else if (swState == 3) {
                    pwmWrite(LED_WHITE, 255); // duty cycle 100%
                    printf("duty: 100\n");//파이썬은 PWM핀 0~1, C는 0~255
                }
            }
        }
        usleep(10000); // debounce delay
    }

    // 프로그램 종료 시 LED 끄기
    pwmWrite(LED_WHITE, 0);

    return 0;
}
