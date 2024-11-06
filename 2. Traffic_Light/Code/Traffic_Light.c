#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t stop = 0;

// Ctrl+C 시 호출될 핸들러
void inthand(int signum) {
    stop = 1;
}

int main() {
    // GPIO 핀 초기화
    wiringPiSetupGpio(); // BCM 핀 번호를 사용

    // LED 핀 번호 설정
    int leds[] = {2, 3, 4, 20, 21};
    int numLeds = sizeof(leds) / sizeof(leds[0]);

    // 핀 모드 설정
    for (int i = 0; i < numLeds; i++) {
        pinMode(leds[i], OUTPUT);
    }

    // SIGINT(인터럽트) 신호에 핸들러 등록
    signal(SIGINT, inthand);

    // LED 제어 루프
    while (!stop) {
        // 상태 1: (0, 0, 1, 1, 0)
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[2], HIGH);
        digitalWrite(leds[3], HIGH);
        digitalWrite(leds[4], LOW);
        sleep(3);

        // 상태 2: (0, 1, 0, 1, 0)
        digitalWrite(leds[0], LOW);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], LOW);
        digitalWrite(leds[3], HIGH);
        digitalWrite(leds[4], LOW);
        sleep(1);

        // 상태 3: (1, 0, 0, 0, 1)
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], LOW);
        digitalWrite(leds[2], LOW);
        digitalWrite(leds[3], LOW);
        digitalWrite(leds[4], HIGH);
        sleep(3);
    }

    // 프로그램 종료 시 모든 LED 끄기
    for (int i = 0; i < numLeds; i++) {
        digitalWrite(leds[i], LOW);
    }

    return 0; // 프로그램 정상 종료
}