//정적 스택

Element data[MAX_SIZE];
int top; //얘넨 그냥 기억해둘 것

void error(char Str[]) {
    printf("%s", Str); //(손코딩)char 써야 함, Str[]이 아니라 Str임
    exit(1); //(손코딩)끝내줘야 반환을 안하지
}

void init_stack() {
    top = -1;
}
int is_empty() {
    if(top == -1) return 1;
    return 0;
    //(손코딩)return (top == -1)..? 이런거였나(맞음)
}
int is_full() {
    if(top == MAX_SIZE - 1) return 1;
    return 0;
}
void push(Element e) { //(손코딩)반환형이 없는데 왜 return을 쓰니..
    if(is_full()) error("Overflow Error!");
    data[++top] = e; //(손코딩)더한 위치에 저장. 얘 중요하다(특히,e 값을 집어넣어 함에 유의)
}
Element pop() {
    if(is_empty()) error("Underflow Error!");
    return data[top--]; //(손코딩)에러나면 exit(1)로 끝나버려서, else 안써도 됨(함수들 다 마찬가지임, error를 거치게 되어있어서.)

}
Element peek() {
    if(is_empty()) error("Underflow Error!");
    return data[top];
}