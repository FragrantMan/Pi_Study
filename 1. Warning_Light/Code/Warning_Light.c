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
    int led1 = 16;
    int led2 = 20;
    int led3 = 21;

    // 핀 모드 설정
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);

    // SIGINT(인터럽트) 신호에 핸들러 등록
    signal(SIGINT, inthand);

    // LED 점멸 루프
    while (!stop) {
        digitalWrite(led1, HIGH); // LED1 켜기
        digitalWrite(led2, HIGH); // LED2 켜기
        digitalWrite(led3, HIGH); // LED3 켜기
        sleep(1); // 1초 대기

        digitalWrite(led1, LOW);  // LED1 끄기
        digitalWrite(led2, LOW);  // LED2 끄기
        digitalWrite(led3, LOW);  // LED3 끄기
        sleep(1); // 1초 대기
    }

    // 프로그램 종료 시 모든 LED 끄기
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    return 0; // 프로그램 정상 종료
}