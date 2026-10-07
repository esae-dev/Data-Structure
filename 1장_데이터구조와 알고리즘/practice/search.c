// sequential_search.c_ 함수 따로 안두고 만든 버전
#include <stdio.h>

int main(void) {
    int A[10] = { 5, 9, 10, 17, 21, 29, 33, 37, 38, 43 };
    int index;
    int key = 5;

    for(int i=0; i<10; i++) {
        if(A[i] == key) printf(" %d의 위치 = %d\n", key, index);
    }
}