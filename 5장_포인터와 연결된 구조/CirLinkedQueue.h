// 5.8 연결된 큐의 구현(184p), 5.10 연결된 큐의 size()연산
//연결된 큐 삽입/삭제: O(1)
typedef struct Node {
    Element data;
    struct Node* next; //link 필드
} Node; //(Node p가 있고, 그 안에 Node link(next)가 들어있는 구조인거임. p 안에 p 다음 주소가 같이 있는데, 얘네 둘이 어떤 우열 관계가 아니라는 걸 기억해야 함. 그냥 둘 다 있는거임)

Node* rear = NULL; //rear를 중심으로 구현

Node* alloc_Node(Element e) {
    Node* p = (Node*)malloc(sizeof(Node)); //노드 공간 만들고
    p->data = e; //할당
    p->next = NULL; //할당
    return p; //이걸 보냄
}
Element free_Node(Node* p) {
    Element e = p->data; //date 주소 다시 받아옴(e는 temp같은 역할임)
    free(p); //노드 p 제거
    return e; //값만 다시 돌려줌
}
void error(char* Str) {
    printf("%s\n", Str);
    exit(1);
}
void init_queue() {
    rear == null; //front = rear = 0 초기화 필요 없이, rear만 봄
}
int is_full() {
    return 0; //front랑 rear+1(나머지)이 같네 뭐네도 필요 없음. 연결 구조이니까
}
int is_empty() {
    return rear == null;
}
void enqueue(Element e) {
    Node* p = alloc_node(e);
    if(is_empty()) { //비어있는 경우: p를 rear와 p 다음주소에 모두 넣어둠(노드가 하나이니 첫 번째이자 마지막이 됨)
        rear = p;
        p->next = p; //다시 돌아오게 만듦
    } else { //뭔가 들어있는 경우: rear의 다음주소를 p의 next에, p 주소를 rear 다음주소에, p 주소를 rear로
        p->next = rear->next; //p 다음주소가 rear 다음주소(front)를 가짐(얘가 이제 rear 다음주소임)
        rear->next = p; //rear 다음주소는 p 주소를 가져감(얜 그냥 link고) <-핵심 문제
        rear = p; //rear는 p를 가리켜야 함
    } /* rear -> next = p가 핵심임. 
        원래 rear였던 애 뒤로 P가 추가되는거잖음? 그니까 rear->next가 p를 가리켜야 함
        한 마디로, 이제 더이상 rear가 아니잖음? 그니까 C->next같은걸로 생각하면 됨.
        C->next랑 rear 모두 p를 가리켜야 하잖음? C는 다음 주소를 연결, rear는 마지막 노드 연결이니까.
        그니까 둘 다 p를 가리키는거임. rear->next가 여전히 rear가 아니라는 것에 주의(A,B,C에서 C 자리라 생각해라)
        */
}
Element dequeue() {
    if(is_empty()) error("Underflow Error!");
    Node* p = rear->next; //rear 다음주소 가져옴(p->next는 rear->next의 next 위치가 되는 것)
    if(rear == p) rear = NULL; //rear 다음주소랑 rear가 가리키는게 같음(노드 하나) -> 바로 NULL 처리
    else rear->next = p->next; //(다를 경우)원래 front 주소 담당하던 애랑 front 다음 애랑 연결시켜줌(front는 빼버릴거니까)
    return free_node(p); //p 삭제하고 데이터 반환
}
Element peek() {
    if(is_empty()) error("Underflow Error!");
    return rear->next->data; 
} /* rear의 다음주소(front)에 있는 데이터 가져옴(dequeue에서 p = rear->next하는거랑 이유가 같음. 
    dequeue는 rear->next의 link를 연결하고, peek는 rear->next의 data를 바로 받아오는 것 ) */
void destroy_queue() {
    while(is_empty() == 0) dequeue();
}