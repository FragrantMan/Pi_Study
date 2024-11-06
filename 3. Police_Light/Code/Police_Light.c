#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LED_RED 23
#define LED_BLUE 24
#define BUTTON_PIN 21

int main() {
    // GPIO 초기화
    wiringPiSetupGpio();

    // 핀 모드 설정
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);

    int swState = 0;
    int lastButtonState = LOW;
    int buttonState; //파이썬과 다르게 on/off를 저장할 기존 
//스위치 상태+ 이전 버튼 상태, 현재 버튼 상태 총 2개의 변수가
//더 필요하다.

    // 메인 루프
    while (1) {
        buttonState = digitalRead(BUTTON_PIN);

        // 버튼이 눌렸을 때
        if (buttonState == HIGH && lastButtonState == LOW) {
            swState = !swState; // 상태 토글
            usleep(500000); // 0.5초 대기
        }

        lastButtonState = buttonState;

        // 상태에 따라 LED 제어
        if (swState == 1) {
            digitalWrite(LED_RED, HIGH);
            digitalWrite(LED_BLUE, LOW);
            usleep(100000); // 0.1초 대기
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_BLUE, HIGH);
            usleep(100000); // 0.1초 대기
        } else {
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_BLUE, LOW);
        }
    }

    return 0;
}
