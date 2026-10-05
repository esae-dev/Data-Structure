//1.3 순차 탐색
int sequential_search(int A[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (A[i] == key) return i;
    } return -1;
}

int main(void) {
    int A[] = {10,20,30,40,50};

    int result = sequential_search(A, 5, 30); //배열 인덱스를 돌려줌, 따라서 result == 2 (A[2]니까)

    printf("%d\n", result);

    return 0;
}