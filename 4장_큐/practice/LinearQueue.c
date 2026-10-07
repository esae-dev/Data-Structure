//선형 큐(참고용)
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8
typedef int Element;
#include "LinearQueue.h"

void print_queue(char msg[]) {
    printf("%s front=%d, rear=%d --> ", msg, front, rear);

    for(int i = front + 1; i <= rear; i++)
        printf("%2d", data[i]);

    printf("\n");
}

int main(void) {
    init_queue();

    for(int i=1; i<7; i++)
        enqueue(i);

    print_queue("enqueue 1~6: ");

    for(int i=0; i<4; i++)
        dequeue();

    print_queue("dequeue 4회: ");

    enqueue(7);

    print_queue("enqueue 7: ");

    return 0;
}