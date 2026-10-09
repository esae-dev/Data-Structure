// 3.1 배열을 이용한 스택의 구현(84p)
Element data[MAX_SIZE]; //int data[MAX_SIZE]랑도 같음. 그냥 Element 써서 push, pop, peek 쓰기 편하게 해둔 것(단, 구조체 쓰이는 3.4부터는 다름)
int top;

void error(char str[]) {
    printf("%s\n", str);
    exit(1); //에러메세지 출력&종료
}
void init_stack() { //-1에서 시작
    top = -1;
}
int is_empty() { //-1이면 비었다는 뜻
    if(top == -1) return 1;
    else return 0; // return top == -1
}
int is_full()  { //최대에서 -1(-1에서 시작해서 한 칸 더 차지함)한 값이 top과 같으면 꽉 찬거
    if(top == (MAX_SIZE - 1)) return 1; //
    else return 0; // return (top == (MAX_SIZE - 1));
}
void push(Element e) {
    if(is_full()) error("Overflow Error!"); //full이면 error 호출
    else data[++top] = e; //아닐 경우 top 증가시키고 e 복사(그냥 더해주고 리턴)
}
Element pop() {
    if(is_empty()) error("Underflow Error!");
    return data[top--]; //top 요소 반환하고 감소시킴(temp에 담아두고 --하고 반환하는 모양이여도 됨)
}
Element peek() {
    if(is_empty()) error("Underflow Error!");
    return data[top]; //top 요소 반환만 함
}