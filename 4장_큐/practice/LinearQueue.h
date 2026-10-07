// 선형 큐(참고용, ai한테 대충 써보라 한거라 바로 원형큐 붙잡고 공부하는게 나음. 진짜 그냥 참고만)
Element data[MAX_SIZE];
int front, rear;

void error(char* str) {
    printf("%s\n", str);
    exit(1);
}

void init_queue() {
    front = rear = 0;
}

int is_empty() {
    return front == rear;
}

int is_full() {
    return rear == MAX_SIZE - 1;
}

void enqueue(Element e) {
    if(is_full()) error("Overflow Error!");

    rear = rear + 1;
    data[rear] = e;
}

Element dequeue() {
    if(is_empty()) error("Underflow Error!");

    front = front + 1;
    return data[front];
}

Element peek() {
    if(is_empty()) error("Underflow Error!");

    return data[front + 1];
}