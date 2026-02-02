#include <stdio.h>
#include <string.h>

int main() {
    char input[100];      // 입력받을 배열
    char stack[100];      // 스택 배열
    int top = -1;         // 스택 포인터
    int i, flag = 1;      // flag: 1이면 회문, 0이면 회문이 아니다

    printf("문자열을 입력하시오: ");
    scanf(" %[^\n]s", input); // 공백을 포함해서 입력을 받을 수 있다.

    // 1. 입력 문자열의 모든 문자를 스택에 삽입하는 과정이다.
    for (i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        // 알파벳인 경우에만 스택에 넣음 (구두점, 스페이스 무시)
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (c >= 'A' && c <= 'Z') c = c + 32; // 모든 문자를 소문자로 통일한다.
            stack[++top] = c; 
        }
    }

    // 2. 스택에서 문자들을 다시 꺼내면서 입력 문자열의 문자와 하나씩 맞춰보는 과정이다.
    for (i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        //비교할 때도 알파벳이 아니면 건너뛴다
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) continue;

        if (c >= 'A' && c <= 'Z') c = c + 32; // 소문자로 통일한다

        // 스택에서 꺼낸 문자와 현재 문자를 대조
        if (stack[top--] != c) { 
            flag = 0; // 하나라도 다르면 회문이 아님
            break;    // 더 이상 검사할 필요 없으므로 탈출
        }
    }

    // 3. 결과 출력
    if (flag == 1) 
        printf("회문입니다.\n");
    else 
        printf("회문이 아닙니다.\n");

    return 0;
}