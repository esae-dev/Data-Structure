// 3.3 문자열 뒤집어 출력하기(86p)
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2000
typedef char Element;
#include "ArrayStack.h"

int main(void) {
    char str[2000];

    init_stack();
    printf("문자열 입력: ");
    gets_s(str, 2000); //단, 영어로 입력 필요. 바이트 단위 차이 때문에 한글 넣으면 깨짐
    for(int i=0; str[i] != '\0'; i++) {
        push(str[i]);
    }
    printf("문자열 출력: ");
    while (!is_empty()) putchar(pop());
    printf("\n");

    return 0;
}