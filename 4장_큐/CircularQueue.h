// 4.1 배열을 이용한 원형 큐의 구현(128p)
Element data[MAX_SIZE];
int front, rear; //스택에선 top만 만들었었음

void error(char* str) {
    printf("%s\n", str);
    exit(1); //에러메세지 출력&종료. 근데 스택에선 str[]썼는데, 여긴 포인터로 접근하네, 왜지?(역할상으론 같음)
}

void init_queue() {
    front = rear = 0; //front와 rear를 둘 다 0으로 초기화(스택에선 top을 -1로 초기화했었음)
}
int is_empty() {
    return front == rear; //스택에선 return top == -1
}
int is_full() {
    return front == (rear + 1) % MAX_SIZE; //스택에선 MAX_SIZE-1이 top과 같으면 최대, 여기선 rear+1이 front와 같으면 최대(&MAX_SIZE는 원형큐 만드려고 쓰는 것)
}
void enqueue(Element e) { //rear만 움직인다는 것에 유의
    if(is_full()) error("Overflow Error!"); //넣기 전에 꽉 찼나 확인
    rear = (rear + 1) % MAX_SIZE; // rear += 1한건데, MAX_SIZE로 나머지 연산 해준거라 생각하면 됨
    data[rear] = e; //rear를 한 칸 회전시키고, e 복사(스택의 push는 top 증가시키고 복사였음)
}
Element dequeue() { //여기서도 마찬가지, push와 enqueue는 값을 받지만, pop, dequeue, peek는 값을 받지 않음
    if(is_empty()) error("Underflow Error!"); //빼기 전에 비었나 확인
    front = (front + 1) % MAX_SIZE; //빼는 건 front 역할임(스택과 다른 부분)
    return data[front]; //front를 한 칸 뒤로 밀고, 그 위치의 값 가져옴(스택의 pop은 복사해온 뒤 top 감소시켰음)
}
Element peek() {
    if(is_empty()) error("Underflow Error!");
    return data[(front + 1) % MAX_SIZE];/*스택에선 top 요소 반환으로 땡침, 큐에선 front가 늘 한 칸 앞에 있으므로, +1을 해줘야 함.
    (저 스택에선 -1을 '미리' 해서 0부터 가게 만들었고, 이 큐에선 0부터 가려면 front가 -1에서 시작해야 해서 이런거라 비슷하긴 함)*/
}
/* pop, dequeue, peek은 Element가 처음에 붙고, push, enqueue는 Element가 나중에 오는 이유?
전자는 Element를 반환하는 거고, 후자는 Element를 입력받기 때문임(대충 int 반환으로 생각해보면 이해됨) */