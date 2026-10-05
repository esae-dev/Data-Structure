// 2.3 함수의 매개변수로 배열 전달(52p)
#include <stdio.h>

void reset_variable(int a) {
    a = 0;
}
void reset_array(int a[], int len) {
    for(int i=0; i<len; i++) {
        a[i] = 0;
    }
}

int main(void) {
    int A[3] = { 10, 20, 30 }, x = 2024;

    reset_variable(x); //값 복사 전달 => 초기화 불가(원본 x는 바뀌지 않음)
    reset_array(A, 3); //배열의 주소 접근 => 초기화 가능

    printf("변수 초기화: x=%d\n", x);
    printf("배열 초기화: ");
    for(int i=0; i<3; i++) {
        printf("A[%d]=%d ", i, A[i]);
    } printf("\n");

    return 0;
}