// 2.1 변수와 배열의 크기 확인(48p)
#include <stdio.h>

int main(void) {
    char c, cA[10];
    int i, iA[10];
    float f, fA[10];
    double d, dA[10];

    printf("<자료형의 크기 [bytes]>\n");
    printf("char 형 = %zu  c의 크기 = %zu\n", sizeof(char), sizeof(c)); //sizeof 오류로 %zu 사용(%d 대신)
    printf("int 형 = %zu  i의 크기 = %zu\n", sizeof(int), sizeof(i));
    printf("float 형 = %zu  f의 크기 = %zu\n", sizeof(float), sizeof(f));
    printf("double 형 = %zu  d의 크기 = %zu\n", sizeof(double), sizeof(d));

    printf("\n<배열의 크기와 요소의 크기 [bytes]>\n");
    printf("cA의 크기 = %zu  cA[0]의 크기 = %zu\n", sizeof(cA), sizeof(cA[0]));
    printf("iA의 크기 = %zu  iA[0]의 크기 = %zu\n", sizeof(iA), sizeof(iA[0]));
    printf("fA의 크기 = %zu  fA[0]의 크기 = %zu\n", sizeof(fA), sizeof(fA[0]));
    printf("dA의 크기 = %zu  dA[0]의 크기 = %zu\n", sizeof(dA), sizeof(dA[0]));

    printf("\n<배열 요소의 수 구하기>\n");
    printf("cA 요소의 수 = %zu개\n", sizeof(cA) / sizeof(cA[0]));
    printf("iA 요소의 수 = %zu개\n", sizeof(iA) / sizeof(iA[0]));
    printf("fA 요소의 수 = %zu개\n", sizeof(fA) / sizeof(fA[0]));
    printf("dA 요소의 수 = %zu개\n", sizeof(dA) / sizeof(dA[0]));

    return 0;
}