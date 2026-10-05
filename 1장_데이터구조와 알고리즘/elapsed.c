//1.2 1부터 1억까지의 합을 구하는 데 걸리는 시간 측정
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long calc_sum(int n) {
    int i;
    long long Sum = 0;
    for(i = 1; i <= n; i++) Sum += i;
    return Sum;
}

int main(void) {
    clock_t start, finish; //CPU 시간 측정할 때 쓰는 자료형
    double duration;

    printf("1부터 10까지의 합은 %d입니다.\n", calc_sum(10)); // 그냥 테스트 함 하는 용도(시간은 안재고, 그냥 합 한 번 구해보기)

    start = clock(); //시작 시간 저장
    calc_sum(100000000);
    finish = clock(); //종료 시간 저장

    duration = (double)(finish - start) / CLOCKS_PER_SEC; //틱 단위를 초로 변환해서 걸리는 시간 구함
    printf("1부터 1억까지의 합을 구하는 데 걸린 시간: %f초 \n", duration);

    return 0;
}