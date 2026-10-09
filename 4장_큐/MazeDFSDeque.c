// 4.9 덱을 이용한 미로 탐색(DFS)(148p)_스택 사용
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct Pos2D {
    int r, c; //row, column
} Element;
#include "CircularDeque.h"

#define MAZE_DIM 6
char map[MAZE_DIM][MAZE_DIM] = {
    { '1', '1', '1', '1', '1', '1' },
    { '0', '0', '1', '0', '0', '1' },
    { '1', '0', '0', '0', '1', '1' },
    { '1', '0', '1', '0', '1', '1' },
    { '1', '0', '1', '0', '0', 'x' },
    { '1', '1', '1', '1', '1', '1' }
};

void push_loc(int r, int c) {
    if(r < 0 || c < 0 || r >= MAZE_DIM || c >= MAZE_DIM) return; //좌표가 범위 밖에 나가면 리턴
    if(map[r][c] != '0' && map[r][c] != 'x') return; //0이나 x가 아니면 리턴

    Element pos = { r, c }; //Pos2D가 구조체라 두 개 받을 수 있음
    add_rear(pos);
}
Element pop_loc() {
    return delete_rear();
}
void print_maze() { //미로 출력
    Element here = get_rear();
    for(int r = 0; r<MAZE_DIM; r++) {
        for(int c=0; c<MAZE_DIM; c++) {
            if(here.r == r && here.c == c) printf("@");
            else printf("%c", map[r][c]);
        } printf("\n");
    }
}

#include <windows.h>

int main(void) {
    init_deque(); //덱 초기화(front = deque = 0)
    push_loc(1, 0); //시작위치 지정

    while(is_empty() == 0) {
        system("cls"); //화면 깨끗이 지우기(windows.h)
        print_maze();
        Sleep(500); //0.5초마다 다음 단계 진행(windows.h)
    

        Element here = pop_loc();
        int c = here.c;
        int r = here.r;
        if(map[r][c] == 'x') {
            printf("\n 미로 탈출 성공\n");
            return;
        }
        else {
            map[r][c] = '.'; //방문했다고 표시하는 용도
            push_loc(r - 1, c);
            push_loc(r + 1, c);
            push_loc(r, c - 1);
            push_loc(r, c + 1); //후보들 넣어두는 것(push_loc에서 범위 바깥이면 종료되게 해둬서, 가능한 경우만 남음)
        }
    } printf("\n미로 탈출 실패");
}