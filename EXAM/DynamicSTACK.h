//동적 스택

void error(char Str[]) {
    printf("%s", Str);
    exit(1);
}
void init_stack() {
    top = -1; //대입연산자 신경쓰기
}
int is_full() {
    top == MAX_SIZE - 1;
}
int is_empty() {
    return top == -1; //Element 쓰지 말고 int 써야 함
}
void push(Element e) {
    MAX_SIZE *= 2;
    (Element*)realloc(sizeof(Element) * MAX_SIZE ); //첫 data랑, 배정 주소 data 빼먹지 않게 조심
}
Element pop() {
    if(is_empty()) error("Underflow Error!");
    return data[top--];
}
Element peek() {
    if(is_empty()) error("Underflow Error!");
    return data[top];
}