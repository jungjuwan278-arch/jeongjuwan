#include <stdio.h>     //2023085923_화학공학과_정주완

void asterisk(int i)
{ 
    if(i > 1) {
        asterisk(i / 2);
        asterisk(i / 2);
    }
    printf("*");
}

int main() {
    asterisk(5);
    return 0;
}
//asterisk(5)는 asterisk(2) 2개를 부르고 별 1개를 찍는다. 
//2개의 asterisk(2)는 asterisk(1) 2개를 부르고 별 1개를 찍는다.
//asterisk(1)은 i>1 조건에 맞지 않아 더 호출하지 않고 별 1개만 찍고 끝난다.
// 따라서 찍히는 별의 총개수는 2*2+2+1=7 이다.
