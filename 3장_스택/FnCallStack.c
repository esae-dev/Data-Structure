// 3.4 스택에 구조체 저장하기(88p)
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct CallInfo { //본명(struct CallInfo)   
    char name[32];
    int param;
};
typedef struct CallInfo Element; //별명(struct CallInfo에 typedef -> Element 별명 붙여줌)

/* typedef struct {
    char name[32];
    int param;
} CallInfo; //첫 번째 별명(익명 구조에 별명 하나 붙여둠)

typedef CallInfo Element; //두 번째 별명(그냥 CallInfo에 Element라는 별명 또 추가)
//(struct로 구조체 만들고, typedef로 별명 짓는다 생각하면 직관적임. 맨 첫 줄은 그냥 struct CallInfo했으니 별명 없이 바로 본명(구조체 자체)인 것)
(둘 구조 헷갈릴 때 보면 됨)*/

#include "ArrayStack.h" //Element가 뭔지가 일단 나온 뒤에 이걸 넣어야 오류가 안 남

int main(void) {
    Element calls[4] = {{ "main()" }, { "factorial()", 3 }, { "factorial()", 2 }, { "factorial()", 1 }};

    init_stack();
    printf("함수 호출 순서: \n");
    for(int i=0; i<4; i++) {
        push(calls[i]);
        printf("\t%s %d\n", calls[i].name, calls[i].param);
    }
    printf("함수 반환 순서: \n");
    while(!is_empty()) {
        Element call = pop();
        printf("\t%s %d\n", call.name, call.param);
    }
    
    return 0;
}