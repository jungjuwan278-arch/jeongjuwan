#include <stdio.h>
#include <string.h>

int main() {
    char exp[100];             // 분석할 괄호를 저장할 배열
    int stack[100];            // 데이터를 저장할 스택 설정
    int top = -1;              // 스택의 제일 상단의 인덱스를 관리하는 변수
    int number = 1;            // 하나씩 증가하는 괄호 번호 변수

    printf("괄호 수식을 입력하시오: "); 
    scanf("%s", exp);          // 사용자가 입력한 괄호를 exp에 저장

    for (int i = 0; i < strlen(exp); i++) {   // 1.문자가 열린 괄호 '(' 인 경우
       
        if (exp[i] == '(') {   // [PUSH] top을 증가시킨 후, 현재 번호를 스택에 저장
            
            stack[++top] = number;  
            
            // 현재 번호를 출력
            printf("%d ", number);  
            
            // 다음 괄호에 부여할 번호 하나 증가
            number++;               
        } 
        
        // 2. 문자가 닫힌 괄호 ')' 인 경우
        else if (exp[i] == ')') {
            // [POP] 현재 top이 가리키는 값을 출력하고 top을  1감소시킨다.
            if (top != -1) {   // top이 -1일 때는 pop하지 않는다.
                printf("%d ", stack[top--]); 
            }
        }
    }
    printf("\n"); // 결과 출력 후 줄바꿈

    return 0; // 프로그램 종료
}