// 5.1 배열을 동적으로 할당하기(162p)
#include <stdio.h>
#include <stdlib.h>

void rand_array(int* A, int n) { //랜덤 입력(0~99)
    for(int i=0; i<n; i++) {
        A[i] = rand() % 100; //배열 A의 요소를 0~99의 무작위 값으로 초기화
    }
}
void print_array(int* A, int n) { //출력(n만큼, 세자리씩 배정해서)
    printf("배열의 요소: ");
    for(int i=0; i<n; i++) printf("%3d", A[i]);
    printf("\n");
}
double average_array(int* A, int n) { //평균 반환
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += A[i];
    } return ((double)sum / n);
}
//사실 다 int* A로 쓸 필요 없고, A[]로 해도 결과 나오긴 나옴. *A로 해도 된다는 걸 보여주려는 것

int main(void) {
    int size;
    printf("배열의 크기: ");
    scanf_s("%d", &size); //사이즈 받기

    int* data = (int*)malloc(sizeof(int) * size); //data 배열 만들기(data[size]랑 사실상 같음. 단, 얘는 사용자가 입력한 size에 따라 배열 크기가 달라질 수 있음)
    rand_array(data, size); //배열 주소랑 크기 모두 줘야 함
    print_array(data, size);
    double avg = average_array(data, size);
    printf("배열의 평균: %lf\n", avg);
    free(data);

}