#include <stdio.h>

int items = 5; // 배열에 저장된 실제 데이터 개수

int delete(int array[], int loc) {
    // 1. 삭제할 값을 미리 변수에 복사해 둔다
    int temp = array[loc]; 
    
    // 2. 삭제된 빈칸을 메우기 위해 뒤쪽 데이터를 한 칸씩 앞으로 이동
    for (int i = loc; i < items - 1; i++) {
        array[i] = array[i + 1]; // 뒤의 값을 현재 칸으로 당겨온다
    }
    
    // 3. 마지막 칸의 중복 데이터를 지우고 전체 개수(items) 1 감소
    array[items - 1] = 0; 
    items--; 
    
    return temp; // 삭제한 값을 최종 반환
}

int main(void) {
    int array[10] = { 100, 200, 300, 400, 500 };
    int loc = 2; // 삭제할 위치 (인덱스 2번)

    // 삭제 함수 실행 및 결과 저장
    int removed = delete(array, loc);

    // 삭제 결과 및 현재 배열 상태 출력
    printf("deleted number: %d\n", removed);
    printf("after deleted: ");
    for (int i = 0; i < items; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}