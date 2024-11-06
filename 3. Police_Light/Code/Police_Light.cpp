#include <wiringPi.h>
#include <iostream> //c는stdio.h ,stdlib.h 2개가 필요
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
    int buttonState;

    // 메인 루프
    while (true) {
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
