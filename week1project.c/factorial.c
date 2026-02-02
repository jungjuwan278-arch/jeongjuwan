#include <stdio.h>                                   //2023085923_화학공학과_정주완
#include <time.h>   // 시간 측정을 위해 필요

// 1. 순환(Recursive) 방법 
int fact_recursive(int n) {
    if (n <= 1) return 1;               // 탈출 조건 
    else return n * fact_recursive(n - 1); // 순환 호출 
}
// 2. 반복(Iteration) 방법 
int fact_iter(int n) {
    int v = 1;
    for (int k = n; k > 0; k--) {       // 루프를 이용한 계산
        v = v * k;
    }
    return v;
}

int main(void) {
    int n = 5; // 임의의 n 설정 
    clock_t start, stop;
    double duration;

    printf("n = %d \n\n", n);

    // [실습 1] Recursive 방법 시간측정
    start = clock();                    // 측정 시작
    int  sum1=fact_recursive(n);
    stop = clock();                     // 측정 종료
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("fact_recursive: %d! = %d\n", n, sum1);
    printf("time: %f s\n\n", duration);

    // [실습 2] Iteration 방법 시간측정
    start = clock();                    // 측정 시작
    int sum2=fact_iter(n);
    stop = clock();                     // 측정 종료
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("fact_iter: %d! = %d\n", n, sum2);
    printf("time: %f s\n", duration);

    return 0;
}