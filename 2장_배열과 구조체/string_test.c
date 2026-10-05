// 2.2 문자열 테스트 (51p)

#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[16] = "Hello World"; //정석
    char s2[16] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'}; //끝 정해줌(가능)
    char s3[] = "Hello World"; //공간 알아서 맞춰줌(가능)
    char s4[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd' }; //끝을 주질 않아서 오류남
    char s5[20];

    //s5 = s1;  오류, 문자열은 대입 연산자로 복사 불가능
    strcpy_s(s5, 20, s1); //_s로 더 안전하게, 메모리 크기 20칸까지 전달(목적지에서 몇 칸 쓰면 되는지 알려줌)

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    printf("s3: %s\n", s3);
    printf("s4: %s\n", s4);
    printf("s5: %s\n", s5);
    printf("문자열 s1의 길이: %zu\n", strlen(s1));
    printf("문자열 s5의 길이: %zu\n", strlen(s5));

}