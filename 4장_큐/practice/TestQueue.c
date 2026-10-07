#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8
typedef int Element;
#include "printQueue.h"

int main(void) {
    Queue q;
    init_queue(&q);

    print_queue(&q);
    enqueue(&q, 10);
    print_queue(&q);
    enqueue(&q, 20);
    print_queue(&q);
    dequeue(&q);
    print_queue(&q);
}