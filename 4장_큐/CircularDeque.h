// 4.7 배열을 이용한 원형 덱의 구현(141p)
#include "CircularQueue.h" //원형 큐 만들 때 썼던 건 수정만 해서 그대로 사용, 덱 만들 때 추가로 필요한 부분만 만들 것

void init_deque() {
    init_queue();
}
void add_rear(Element e) { //enqueue, push, add_rear는 매개변수가 필요하다는 것을 기억
    enqueue(e);
}
Element delete_front() { //dequeue, pop, delete_front는 반환형 필요
    return dequeue();
}
Element get_front() { //peek, get_front도 반환형 필요
    return peek();
}

void add_front(Element e) { //add_front도 매개변수 필요
    if(is_full()) error("Overflow Error!");
    data[front] = e; //data[rear]가 아닌 data[front](그냥 넣고 돌리기)
    front = (front - 1 + MAX_SIZE) % MAX_SIZE; //MAX_SIZE 하나를 미리 더해주어 음수 방지(방향이 반대니까(front - 1))
}
Element delete_rear() {
    if(is_empty()) error("Underflow Error!");
    int prev = rear;
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    return data[prev]; //후단 삭제는 pop()의 top--랑 비슷한데, return하면 함수가 바로 끝나버려서 값을 임시저장했다가 한 칸 내리고 반환해야 함
} //pop--도 temp해두고 --하고 반환하는 느낌이였다 생각하면 됨
Element get_rear() {
    if(is_empty()) error("Underflow Error!");
    return data[rear]; //rear 반환
}