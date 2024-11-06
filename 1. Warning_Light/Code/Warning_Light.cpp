#include <wiringPi.h>
#include <iostream>//<stdio.h> 대신 iostream
#include <signal.h>
#include <unistd.h> //#include <stdlib.h> 는 없어짐

volatile sig_atomic_t stop; // 프로그램 중지 플래그

void inthand(int signum) { stop = 1; } // Ctrl+C 누르면 종료
//inthand는 신호발생시 호출 함수, signum는 신호의 종류구분 정수,
//{stop = 1;} 호출시 stop이 1로 설정 되며 루프 종료
int main() {
    wiringPiSetupGpio(); // 핀에 대한 세팅을 BCM 체계로 초기화

    const int leds[] = {16, 20, 21}; // leds란 정수 배열에 값을 넣고
//const를 사용해 값을 고정하여 안정성 확보
    for (int led : leds) pinMode(led, OUTPUT);// leds라는 배열에서
//led라는 정수 변수를 선언해 가져오고, 핀을 출력으로 설정한다.
    signal(SIGINT, inthand); //신호에 관한 함수를 사용. 인터럽트가 들어오면
    //inthand를 로드

    while (!stop) { // 중지 신호가 올 때까지 반복
        for (int led : leds) digitalWrite(led, HIGH); // leds 내부 항목인 led에 high 설정
        delay(100); // 0.1초 대기
        for (int led : leds) digitalWrite(led, LOW); // 역시 led에 LOW 설정해서 off
        delay(100); // 0.1초 대기
    }

    for (int led : leds) digitalWrite(led, LOW); // 프로그램 종료 시 모든 LED 끄기

    return 0; // 프로그램 정상 종료
}