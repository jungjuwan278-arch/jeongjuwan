#include <stdio.h>   
#include <stdlib.h>  
#include <string.h>  

// 구조체를 만듭니다
typedef struct p {
    int number;        // 숫자를 담을 칸
    char words[21]; // 문자를 담을 칸 (최대 20글자)
} p;                 // 이 구조체를 'p'라고 부릅니다

int main(void) {
    p *input;        // 구조체를 가리킬 포인터 변수를 만듭니다

    input = (p*)malloc(sizeof(p));

    // 할당받는 메모리가 있는지 확인 (없으면 프로그램 종료)
    if (input == NULL) return 1;

    // (->)를 이용해 메모리의 'number' 칸에 100 쓰기
    input->number = 100; 

    // 메모리의 'words' 칸에 "just testing" 글자 복사해서 넣기
    strcpy(input->words, "just testing"); 

    // 결과 확인
    printf("number: %d\n", input->number);
    printf("words: %s\n", input->words);

    free(input);

    return 0; // 프로그램 종료
}