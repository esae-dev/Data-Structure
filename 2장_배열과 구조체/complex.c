// 2.5 구조체를 매개변수로 전달(59p)

#include <stdio.h>
typedef struct {
    double real; //복소수의 실수부
    double imag; //복소수의 허수부
} Complex; //별명 지어준거임

void reset_complex(Complex c) { //값 초기화
    c.real = c.imag = 0.0;
}
void print_complex(Complex c) { //출력(4.1 -> 최소 4칸 사용, 소수점은 1자리만)
    printf("%4.1f + %4.1fi\n", c.real, c.imag);
}

int main(void) {
    Complex a = { 1.0, 2.0 };
    printf("초기화 이전: ");
    print_complex(a);
    reset_complex(a); //실패
    printf("초기화 이후: ");
    print_complex(a); //값이 변하지 않고 유지됨. a가 함수로 전달되는게 아니라, 새로운 매개변수 c로 복사되는 것뿐이기 때문(2.3 함수의 매개변수로 배열 전달 상황과 비슷)

}