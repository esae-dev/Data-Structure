// 4.4 큐를 이용한 피보나치 수 구하기
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
typedef int Element;
#include "CircularQueue.h"

int fibonacci(int n) {
    if(n<=1) return n; //0, 1은 그냥 바로 리턴

    init_queue();
    enqueue(0);
    enqueue(1); // 연속된 피보나치 두 항만 유지하는 구조로 가려고 [0, 1] 만든 것(0, 1 따로 안 빼면 fibonacci(0)했을 때 1이 튀어나옴)
    for(int i = 2; i<= n; i++) {
        int n1 = dequeue(); //front 뺌(엄밀히는 front+1 자리)
        int n2 = peek(); //rear 확인
        enqueue(n1+n2); //둘 더해서 enqueue(이러면 두 항이 [n2, n1+n2]가 되는 셈)
    }
    dequeue(); //n2 제거
    return dequeue(); //n1+n2만 반환
}

int main(void) {
    printf("피보나치 수열: ");
    for(int i=0; i<16; i++) {
        printf("%d,", fibonacci(i));
    } printf("\n\n");
}

/* 여담으로, 사실 피보나치는 큐 안써도 구할 수 있음.
반복문 안에 변수 세 개(x=0, y=1, temp) 만들고, temp=x+y, x=y, y=temp만 해도 가능함.
오래된 데이터를 버리고 두 개씩만 남긴다는 건 의미가 있으나, 결국 피보나치는 최종 값만 있으면 되는거라 굳이 필요 없음(n2까지 저장하는거니까 큐는) */