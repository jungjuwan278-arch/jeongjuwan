#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* link;
} ListNode;

// 새로운 노드를 생성하는 함수
ListNode* create_node(int data) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->data = data;
    new_node->link = NULL;
    return new_node;
}

// 리스트의 끝에 노드를 추가하는 함수
void insert_node_back(ListNode** head, ListNode* new_node) {
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    ListNode* temp = *head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = new_node;
}

// [작성하신 코드] 두 리스트를 교대로 병합하는 함수
ListNode* alternate(ListNode* A, ListNode* B) {
    ListNode* p = A, * q = B, * t = NULL;
    while (p != NULL || q != NULL) {
        if (p != NULL) {
            insert_node_back(&t, create_node(p->data));
            p = p->link;
        }
        if (q != NULL) {
            insert_node_back(&t, create_node(q->data));
            q = q->link;
        }
    }
    return t;
}

// 리스트 출력 함수
void print_list(const char* msg, ListNode* head) {
    printf("%s: ", msg);
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    printf("NULL\n");
}

int main() {
    ListNode *A = NULL, *B = NULL, *T = NULL;

    // 리스트 A 생성: 1, 3, 5
    insert_node_back(&A, create_node(1));
    insert_node_back(&A, create_node(3));
    insert_node_back(&A, create_node(5));

    // 리스트 B 생성: 2, 4, 6, 8, 10
    insert_node_back(&B, create_node(2));
    insert_node_back(&B, create_node(4));
    insert_node_back(&B, create_node(6));
    insert_node_back(&B, create_node(8));
    insert_node_back(&B, create_node(10));

    print_list("리스트 A", A);
    print_list("리스트 B", B);

    // 병합 실행
    T = alternate(A, B);
    print_list("병합된 리스트 T", T);

    return 0;
}