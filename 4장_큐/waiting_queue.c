// 4.3 큐에 웨이팅 정보 저장하기(131p)
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
struct waiting {
    int id; //대기번호
    int nperson; //인원
    char info[32]; //전화번호
};
typedef struct waiting Element; //별명 짓기
#include "CircularQueue.h"

int main(void) {
    Element waiting[4] = { { 12, 2, "010-xxxx-1234"}, { 13, 4, "010-xxxx-7809"}, { 14, 3, "010-xxxx-4785"}, { 15, 2, "010-xxxx-7345"} };

    init_queue();
    for(int i=0; i<4; i++)  {
        printf("웨이팅 신청을 완료했습니다. 대기번호: %d번 인원:%d명\n", waiting[i].id, waiting[i].nperson);
        enqueue(waiting[i]); //웨이팅 정보 저장(waiting[i] 구조체가 data[]에 복사되어 저장되는 것)
    }
    while(!is_empty()) {
        Element w = dequeue(); //w가 하나씩 가져오는 것(int x = pop()으로 생각하면 됨. 값 하나씩 받아오는 그 감성)
        printf("웨이팅 번호 %d번 입장하실 차례입니다. (%d명, %s)\n", w.id, w.nperson, w.info);
    } //Element w에서 정보 받아옴
}