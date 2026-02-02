#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct ListNode {
    int data;
    struct ListNode* link;
} ListNode;

// 리스트의 끝에 노드를 추가하는 함수 (입력 순서 유지)
ListNode* insert_last(ListNode* head, int value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = NULL;

    if (head == NULL) {
        return p;
    }

    ListNode* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = p;
    return head;
}

// [작성하신 코드] 모든 노드의 데이터 합을 구하는 함수
int get_sum(ListNode* head) {
    int sum = 0;
    ListNode* p = head;
    while (p != NULL) {
        sum += p->data;
        p = p->link;
    }
    return sum;
}

int main() {
    ListNode* head = NULL;
    int count, value;

    printf("노드의 개수를 입력하시오: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("데이터를 입력하시오: ");
        scanf("%d", &value);
        head = insert_last(head, value);
    }

    // 결과 출력
    printf("연결 리스트 데이터의 총합: %d\n", get_sum(head));

    // 메모리 해제
    ListNode* p = head;
    while (p != NULL) {
        ListNode* next = p->link;
        free(p);
        p = next;
    }

    return 0;
}