// 4.6 구조체와 매개변수 전달을 이용한 큐의 활용(135p)
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8
typedef int Element;
#include "QueueStruct.h"

void print_queue(Queue* q, char msg[]) { //msg[]는 설명 문구 출력용
    printf("%s front=%d, rear=%d --> ", msg, q->front, q->rear);
    int size = (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
    printf("\n");
}

int main(void) {
    Queue q;
    init_queue(&q); //주소를 전달함
    for(int i=1; i<7; i++) enqueue(&q, i);
    print_queue(&q, "enqueue 1~6: ");

    for(int i=0; i<4; i++) dequeue(&q);
    print_queue(&q, "dequeue 4회: ");

    for(int i=7; i<10; i++) enqueue(&q, i);
    print_queue(&q, "enqueue 7~9: ");

    return 0;
}