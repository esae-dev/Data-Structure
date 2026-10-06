// 3.5 괄호 검사 프로그램(92p)
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef char Element;
#include "ArrayStack.h"

int check_matching(char str[]) { //원본은 expr[]인데, 혼동 방지를 위해 str[]로 변경. 2차원인지 1차원인지 헷갈림
    int i = 0, prev;

    init_stack();
    while (str[i] != '\0') { //문자열 끝에 다다르면 종료
        char ch = str[i++]; //그 칸의 값을 ch에 받고 str 한 칸 밀기
        if(ch == '[' || ch == '(' || ch == '{') push(ch); //열린 괄호면 일단 스택에 삽입(**이 코드에선 여는 괄호만 push하는게 핵심임**)
        else if(ch ==']' || ch == ')' || ch == '}') {
            if (is_empty()) return 2; //닫는 괄호가 나왔을 때, 열린 괄호가 없었다면(스택 공백)_오류 2

            prev = pop(); //pop으로 전에 들어간 열린 괄호랑, 지금 찾는 ch(str[i]랑 짝이 맞나 보고, 지우는 역할 
            if((ch == ']' && prev != '[') || (ch == ')' && prev != '(') || (ch == '}' && prev != '{')) return 3;
        } //짝이 안 맞으면_오류 3
    }
    if(!is_empty()) return 1; //다 끝났는데 여전히 스택 뭔가 남아있음(pop 덜 됨, 여는 괄호가 더 많았다는 의미)_오류 1
    else return 0; //오류 1: 여는 괄호가 더 많음, 오류 2: 닫는 괄호가 먼저 뜸, 오류 3: 짝이 안맞음
}

int main(void) {
    char expr[4][80] = {
        "{A[(i+1)]=0;}", "if((i==0) && (j==0)", "while(n<8)){n++;}", "arr[(i+1]) = 0;" };

    for(int i=0; i<4; i++) {
        int errCode = check_matching(expr[i]); //expr[i] 한 줄을 보내주는 것
        if(errCode == 0) printf("%-20s -> 정상\n", expr[i]); //errCode == 0
        else printf("%-20s -> 오류(조건%d 위반)\n", expr[i], errCode); //나머지 경우(오류 케이스)
    } //%-20s: %s(문자열), 왼쪽 정렬 후 20칸 확보( '->' 뒤쪽 예쁘게 맞추려는 것)
}