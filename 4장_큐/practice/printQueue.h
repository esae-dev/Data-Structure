typedef struct Queue{ //지금은 일단 자기참조를 위한 앞 이름을 적어둔거라고만 보면 됨(C 작성 습관같은 것)_5.4 175p '연결된 스택의 구현'에서 볼 예정(모양 비교는 2장 practice/student.c 봐도 됨)
    Element data[MAX_SIZE];
    int front;
    int rear;
} Queue;
//아예 헤더파일에서 구조체를 만들어놓고 감(기존까진 .c 파일에서 typedef int Element로 헤더파일의 Element와 연결하는 정도였음. <-이번과 다른 이유? 이번엔 물건이 아니라 바구니 자체니까.)

void error(char* str) {
    printf("%s\n", str);
    exit(1);
}
void init_queue(Queue *q) {
    q->front = q->rear = 0; //그냥 앞에 'q->'가 붙었다고 생각하면 됨
}
int is_empty(Queue* q) {
    return q->front == q->rear;
}
int is_full(Queue* q) {
    return q->front == (q->rear + 1) % MAX_SIZE;
}
void enqueue(Queue* q, Element e) { //Queue를 지정해주고, 쓰던 대로 Element
    if(is_full(q)) error("Overflow Error!"); //(q): 매개변수가 이제 들어간다
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = e;
}
Element dequeue(Queue* q) {
    if(is_empty(q)) error("Underflow Error!");
    q->front = (q->front + 1) % MAX_SIZE; //큐를 한 칸 밀고
    return q->data[q->front]; //front 가져옴
}
Element peek(Queue* q) {
    if(is_empty(q)) error("Underflow Error!");
    return q->data[(q->front + 1) % MAX_SIZE]; //(front+1)%MAX_SIZE 바로 확인
}
void print_queue(Queue* q) {
    printf("front=%d, rear=%d --> ", q->front, q->rear);
    int size =(q->rear - q->front + MAX_SIZE) % MAX_SIZE;
    for(int i = q->front + 1; i <= q->front + size; i++) {
        printf("[%d]%2d", i, q->data[i%MAX_SIZE]);
    } printf("\n");
}







/*
[구조체 Queue 설명]

전에 했던 건 구조체 물건 만들기(Element), 지금은 구조체 바구니 만들기(Queue).
구조체 물건 Element를 만들고, 그걸 data[]라는 정적인 바구니에 넣었음
그리고 이번엔 Queue 안에 front랑 rear를 처음부터 넣어놓고, 기능을 묶어 쓰는 마법 바구니를 만들겠다는 것.

기존 바구니(Element data[])는 int front, int rear를 그냥 전역변수로 선언해놓고 썼는데, 아예 그 기능들을 묶어 쓰는 바구니를 만들겠다는 것.
(이를테면 기존 방식은 front2, rear2 이런거 계속 선언해줘야 함)
*/

/*
[포인터 설명]

기존엔 큐가 하나였기 때문에 그냥 헤더파일을 통으로 가져와 쓰면 됐음(void enqueue(Element e)를 해도 어차피 전역(하나)이니까)
근데 이걸 구조체로 묶고 Queue라는 타입으로 만들면, 큐 자체를 매개변수로 넘겨주어야 함(어떤 큐인지를 모르니까)
->근데 여기서 문제가, 2.3, 2.5때처럼 그냥 값을 넘겨주면 값이 복사가 되어 들어감. 원래의 큐는 그대로가 된다는 것.
따라서 포인터로 줘서 큐 내부가 변경될 수 있도록 해줘야 한다는 것.
즉, '매개변수 전달'에 포인터가 필요하단 점이 핵심임.(값만 넘기면 복사되어 들어가므로)

한줄 요약: 여러개라 매개변수 필요, 매개변수에 들어간 값 자체를 바꾸려면 포인터 필요
*/