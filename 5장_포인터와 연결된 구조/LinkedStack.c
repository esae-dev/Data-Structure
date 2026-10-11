// 5.5 연결된 스택의 활용(176p), 5.7 스택 요소를 입력순으로 출력
#include <stdio.h>
#include <stdlib.h>

typedef int Element;
#include "LinkedStack.h"

//5.7 스택 요소를 입력순으로 출력
void print_stack(Node* p) {
    for( Node*p = top; p != NULL; p = p->link) printf("%3d", p->data);
} //top에서 link타고 NULL까지, 구조체 p의 data 출력
void print_recur(Node* p) {
    if(p != NULL) {
        print_recur(p->link); //일단 link부터 처리(그 전 주소)
        printf("%3d", p->data);
    }
}

int main(void) {
    int A[7] = { 0, 1, 1, 2, 3, 5, 8 };

    init_stack();
    printf("스택 테스트\n 입력 데이터: ");
    for(int i=0; i<7; i++) {
        printf("%3d", A[i]);
        push(A[i]); //집어넣음
    }
    printf("\n 출력 데이터: ");
    while(!is_empty()) printf("%3d", pop()); //다시 빼냄
    printf("\n");

    destory_stack();
}