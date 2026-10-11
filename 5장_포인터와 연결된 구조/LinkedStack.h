// 5.4 연결된 스택의 구현(175p)_ MAX_SIZE가 필요 없음, 5.6 연결된 스택의 size()연산(178p)
typedef struct Node { //자기참조 구조체
    Element data; //본체 부분(데이터)
    struct Node* link; //서로 연결되도록 만들어둔 고리 부분(연결고리)
} Node;

Node* top = NULL; //top을 Null로 시작

Node* alloc_node(Element e) { //새 노드 만들기
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e; //받은 데이터 e 집어넣고
    p->link = NULL; //링크는 연결 안됐으니 일단 NULL
    return p;
}
Element free_node(Node* p) { //노드 지우기
    Element e = p->data;
    free(p);
    return e; //데이터는 다시 돌려주고(복사해감, pop에서 필요해서), 노드 삭제
}

//아래는 스택 연산들
void error(char* Str) {
    printf("%s", Str);
    exit(1);
}
void init_stack() {
    top = NULL; //-1이 아니라, 아예 NULL로 시작
}
int is_full() {
    return 0; //그냥 바로 종료하겠단건가..? -> "항상 꽉 안찬다"
}
int is_empty() {
    return top == NULL; //NULL이면 빈거라고 1 돌려준다는 것
}
void push(Element e) { //(중요) 여기서의 top은 숫자 인덱스가 아닌 맨 위 노드의 주소 자체를 의미함
    Node* p = alloc_node(e);
    p->link = top;
    top = p; //top 주소(기존)를 p의 link에 넣고, top에 p의 주소(새거)를 넣음(그리고, 오버플로우는 안 남)
}
Element pop() {
    if(is_empty()) error("Underflow Error!"); //돌려줄 게 없으면 여전히 오버플로우는 남
    Node* p = top; //top(주소) p로 복구
    top = p->link; //link에 들고있던 걸 top의 값으로 돌려줌
    return free_node(p); //노드 삭제
}
Element peek() {
    if(is_empty()) error("Underflow Error!");
    return top->data; //주소 top이 가리키는 data값 반환
}

void destory_stack() {
    while (is_empty() == 0) pop(); //값 다 삭제
}

//5.6 연결된 스택의 size()연산(178p)
int size() {
    int count = 0;
    for(Node* p = top; p != NULL; p = p->link) count++; //top에서 시작, link를 쭉 따라가다가 끝(NULL)에서 종료
    return count;
}