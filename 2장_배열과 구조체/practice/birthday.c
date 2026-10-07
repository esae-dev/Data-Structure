// 구조체를 포함하는 구조체
#include <stdio.h>
#include <string.h>

typedef struct {
    int year, month, date;
} Birthday;

typedef struct {
    char name[20];
    Birthday birthday;
} Friend;

int main(void) {
    Friend f_list[100] = {0}; //전부 0으로 초기화(C 규칙: 들어간 값 제외한 값은 모두 0으로 바뀜)

    strcpy_s(f_list[0].name, sizeof(f_list[0].name), "Jinseog");
    f_list[0].birthday.year = 2000;
    f_list[0].birthday.month = 8;
    f_list[0].birthday.date = 10;

    printf("%s: %d-%d-%d\n",
        f_list[0].name,
        f_list[0].birthday.year,
        f_list[0].birthday.month,
        f_list[0].birthday.date);

    return 0;
}