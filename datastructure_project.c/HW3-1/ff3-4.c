#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//구조체 정의
typedef struct {
    char list[30];    // 할 일 내용 
    int priority;     // 우선순위 
} element;

typedef struct {
    element heap[50];
    int heap_size;
} HeapType;

//생성 및 초기화 함수
HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
    h->heap_size = 0;
}

// 최소 히프 삽입 로직 
void insert_heap(HeapType* h, element item) {
    int i = ++(h->heap_size);
    while ((i != 1) && (item.priority < h->heap[i / 2].priority)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

//최소 히프 삭제 로직 
element delete_heap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
        // 숫자가 더 작은 자식을 선택 
        if ((child < h->heap_size) && (h->heap[child].priority > h->heap[child + 1].priority))
            child++;

        if (temp.priority <= h->heap[child].priority) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

int main(void) {
    HeapType* heap = create();
    init(heap);
    element e;


    printf("삽입(i), 삭제(d): i\n");
    printf("할 일: 이메일 작성\n");
    strcpy(e.list, "이메일 작성"); 
    printf("우선순위: 10\n");
    e.priority = 1;
    insert_heap(heap, e);

    
    printf("삽입(i), 삭제(d): i\n");
    printf("할 일: 청소하기\n");
    strcpy(e.list, "청소하기");
    printf("우선순위: 3\n");
    e.priority = 2;
    insert_heap(heap, e);

    // 삭제 및 결과 출력
    printf("삽입(i), 삭제(d): d\n");
    e = delete_heap(heap);
    printf("제일 우선순위가 높은 일은 \"%s\"\n", e.list);

    free(heap);
