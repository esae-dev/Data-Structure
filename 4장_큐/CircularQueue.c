// 4.2 원형 큐의 활용(130p)
#include <stdio.h>
#include <stdlib.h> //마찬가지로 exit 쓰기 위함

#define MAX_SIZE 8 //스택때랑은 크기가 다름(그땐 막 100단위였음)
typedef int Element;
#include "CircularQueue.h"

void print_queue(char msg[]) { //큐의 내용 출력
    printf("%s front=%d, rear=%d --> ", msg, front, rear);
    int size = (rear - front + MAX_SIZE) % MAX_SIZE; //현재 큐 안에 들어 있는 원소 개수, rear가 front보다 작을 경우를 대비해서 MAX_SIZE를 더해줌(한 바퀴 돌 수도 있으니까. %MAX_SIZE로 원형 큐 만들고.)

    for(int i = front + 1; i <= front + size; i++) printf("%2d", data[i%MAX_SIZE]); //front+1에서 시작, front+size까지 돌면서 출력. i%MAX_SIZE인 이유는 배열 끝을 넘어가면 돌아가게 하기 위함임
    printf("\n");
}

int main(void) {
    init_queue(); //큐 초기화
    for(int i=1; i<7; i++) enqueue(i); //~>일단 삽입이나 빼는 걸 먼저 해두고, print_queue 호출로 결과만 볼 것
    print_queue("enqueue 1~6: "); //1부터 6까지 삽입

    for(int i=0; i<4; i++) dequeue();
    print_queue("dequeue 4회: "); //(중요)인덱스 기준으로 0부터 3까지 뺌

    for(int i=7; i<10; i++) enqueue(i);
    print_queue("enqueue 7~9: "); //7부터 9까지 삽입
}