// 5.2 동적 할당을 이용한 배열구조 스택
int MAX_SIZE = 10; //처음 공간은 10(#define이 아님 => 변수로 선언해두고 나중에 바꾸기 위함)
Element* data = NULL; //아직 배열 공간 없음(data[]가 null이라고 생각)
int top;

void error(char Str[]) {
    printf("%s", Str);
    exit(1);
}

void init_stack() {
    data = (Element*)malloc(sizeof(Element) * MAX_SIZE); //동적 스택 만들거니까 여기서 할당함(미리 안만듦)
    top = -1;
}
int is_empty() {
    if(top == -1) return 1;
    return 0;
}
int is_full() {
    if(top == MAX_SIZE - 1) return 1;
    return 0;
}
void push(Element e) { //이 부분이 정적 스택과 다름. 값 넣다가 포화 상태 되면 
    if(is_full()) {
        MAX_SIZE *= 2; //error가 아니라, 그냥 크기를 키워버림
        data = (Element*)realloc(data, sizeof(Element) * MAX_SIZE); //realloc(기존 메모리 공간의 위치)임, 그리고 그걸 다시 data에 넣어줌.
        printf("realloc(%d)\n", MAX_SIZE);
    }
    data[++top] = e;
}
Element pop() {
    if(is_empty()) error("Underflow Error!");
    return data[top--];

}
Element peek() {
    if(is_empty()) error("Underflow Error!");
    return data[top];
}