// 4.8 원형 덱의 활용
#include <stdio.h>
#include <stdlib.h> //error일 때 exit(1) 쓰기 위함

#define MAX_SIZE 10
typedef int Element;
#include "CircularDeque.h"

void print_deque(char msg[]) { //msg는 문자열 출력 용도
    printf("%s front=%d, rear=%d --> ", msg, front, rear);
    int size = (rear - front + MAX_SIZE) % MAX_SIZE;

    for(int i=front + 1; i <= front + size; i++) {
        printf("%2d ", data[i % MAX_SIZE]);
    } printf("\n");
}

int main(void) {
    init_deque(); //front와 rear를 0으로 초기화
    for(int i = 0; i < 9; i++) { //0부터 8까지
        if(i%2) add_front(i); //홀수면 전단삽입
        else add_rear(i); //짝수면 후단삽입
    }
    print_deque("원형 덱 홀수-짝수  ");
    printf("\tdelete_front() --> %d\n", delete_front());
    printf("\tdelete_rear() --> %d\n", delete_rear());
    printf("\tdelete_front() --> %d\n", delete_front());
    print_deque("원형 덱 삭제-홀짝홀");
}
