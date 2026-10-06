// 3.2 스택의 활용(85p)
#include <stdio.h>
#include <stdlib.h> //exit 쓰려면 필요함(메모리, 종료, 변환, 난수같은 표준 기능)

#define MAX_SIZE 100
typedef int Element; //그냥 여러번 쓰려고 이 친구 묶어버린거임
#include "ArrayStack.h"

int main(void) {
    int A[7] = { 0, 1, 1, 2, 3, 5, 8 };

    init_stack();
    printf("스택 테스트\n 입력 데이터: ");
    for(int i=0; i<7; i++) {
        printf(" %d", A[i]);
        push(A[i]); //출력한 애들 차례로 push
    }

    printf("\n 출력 데이터: ");
    while (!is_empty()) {
        printf(" %d", pop()); //empty 될 때까지 pop
    } printf("\n");

    return 0;
}