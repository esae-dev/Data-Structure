//1.1 최댓값 찾기
#include <stdio.h>

int main(void) {
    int max, x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    max = x;
    if(x < y) max = y;
    if(max < z) max = z;

    printf("%d", max);
}