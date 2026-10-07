// 포인터 개념(2.3 배열이랑 연계해서 나감)
#include <stdio.h>

void swap_v(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
void swap_r(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(void) {
    int x = 10, y = 20;
    printf("Original values: x = %d, y = %d\n", x, y);
    swap_v(x, y); //a, b에 x,y 값이 복사되어 들어감 => 원본은 안바뀜
    printf("Swap by value: x = %d, y = %d\n", x, y);
    swap_r(&x, &y); //x, y의 주소 자체가 들어감 => 원본 바뀜(엄밀히 주소 자체는 아니고, 주소를 나타내는 포인터 값을 들고 있는거긴 함, CPU에서 PC가 값을 주소로 썼다 오퍼랜드에 넣었다 하는 것과도 비슷함)
    printf("Swap by reference: x = %d, y = %d\n", x, y);

    return 0;
}