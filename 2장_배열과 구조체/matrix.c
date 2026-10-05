// 2.4 행렬을 2차원 배열로 표현하기(54p)
#include <stdio.h>
#define ROWS 3
#define COLS 3

void print_mat(int m[ROWS][COLS], char* str) { //행렬 출력
    printf("%s\n", str);
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf(" %3d", m[i][j]);
        }printf("\n"); //COLS만큼 출력하고 들여쓰기룰 ROWS만큼 반복
    }
}
void transpose_mat(int m[ROWS][COLS]) { //전치
    for(int i=0; i<ROWS; i++) {
        for(int j=i+1; j<COLS; j++) {
            int tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp; //temp 이용해서 값 서로 바꿔주는 연산. 1.4 has_duplicat_elem.c과 마찬가지로, [0][1], [1][0] 이런 식으로 한쪽 삼각형 부분을 잡고 바꿔주면 바뀌는 방식임
        }
    }
}

int main(void) {
    int mat[ROWS][COLS] = { 4, 0, 1, 1, 6, 5, 7, 3, 6};
    print_mat(mat, "원래 행렬");
    transpose_mat(mat);
    print_mat(mat, "전치 행렬");

    return 0;
}