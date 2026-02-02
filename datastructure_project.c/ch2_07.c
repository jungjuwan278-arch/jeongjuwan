#include <stdio.h>          //2023085923_화학공학과_정주완

int sum(int n)
{
    printf("%d\n", n);      // 현재 호출된 n의 값을 화면에 출력한다. (5, 4, 3, 2, 1, 0 순서)
    if(n < 1) return 1;     // n이 0이 되면 1을 반환하며 순환을 멈춘다.
    else return(n + sum(n - 1)); // n과 (n-1의 합)을 더하여 상위 호출로 반환한다.
                                 // 즉 1+1+2+3+4+5=16 이 반환값으로 출력된다.   
}

int main() {
    int total = sum(5);     // main 함수에서 sum(5)를 호출하여 계산을 시작한다.
    printf("answer: %d\n", total); // 최종 계산된 합계(16)를 출력한다.
    return 0;               
}