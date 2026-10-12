void error(char* Str) {
    printf("%s\n", Str);
    exit(1);
}
void init_queue() {
    front = rear = 0;
}
int is_full() {
    return front == (rear + 1) % MAX_SIZE; //front와 rear+1이 같을 때 꽉 찬 것(rear+1==MAX_SIZE하면 7일 때만 ok가 되어버림) 즉, 항상 front와 rear를 활용해야 함
}
int is_empty() {
    return front == rear;
}
void enqueue(Element e) {
    if(is_full()) error("Overflow Error!");
    rear = (rear + 1) % MAX_SIZE //한 칸 먼저 밀고(rear에 넣기, rear+1인거 기억)
    data[rear] = e;
}
Element dequeue() {
    if(is_empty) error("Underflow Error!");
    front = (front + 1) % MAX_SIZE //한 칸 먼저 밀고(front에 넣기, front+1인거 기억)
    return data[front]; //자연스럽게 front칸 비고, 맨 앞 값도 보내줌
}
Element peek() {
    if(is_empty) error("Underflow Error!");
    return data[(front+1) % MAX_SIZE]; 
}
void destroy_queue() {

}