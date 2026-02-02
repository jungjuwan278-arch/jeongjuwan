#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 이미지의 구조체 정의 스타일 반영 */
typedef struct {
    char list[30];    /* 할 일 내용 */
    int priority;     /* 우선순위 (숫자가 작을수록 높음) */
} element;

typedef struct {
    element heap[50];
    int heap_size;
} HeapType;

/* 이미지 내 HeapType* create() 함수 구현 */
HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

/* 이미지 내 void init() 함수 구현 */
void init(HeapType* h)
{
    h->heap_size = 0;
}

/* 이미지 내 void insert_heap() 함수 구현 (최소 히프) */
void insert_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.priority < h->heap[i / 2].priority)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

/* 이미지 내 element delete_heap() 함수 구현 */
element delete_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;

    while (child <= h->heap_size) {
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

/* 이미지 내 void help() 함수 구현 */
void help()
{
    printf("삽입(i), 삭제(d), 종료(q): ");
}

int main(void)
{
    HeapType* heap;
    heap = create();
    init(heap);
    element e;

    /* 코드 내부에서 데이터를 직접 넣어 실행 결과 출력 */

    // 1. 첫 번째 데이터 삽입
    printf("삽입(i), 삭제(d): i\n");
    printf("할 일: ");
    strcpy_s(e.list, sizeof(e.list), "이메일 작성");
    printf("%s\n", e.list);
    printf("우선순위: ");
    e.priority = 1;
    printf("%d\n", e.priority);
    insert_heap(heap, e);

    // 2. 두 번째 데이터 삽입
    printf("삽입(i), 삭제(d): i\n");
    printf("할 일: ");
    strcpy_s(e.list, sizeof(e.list), "청소");
    printf("%s\n", e.list);
    printf("우선순위: ");
    e.priority = 2;
    printf("%d\n", e.priority);
    insert_heap(heap, e);

    // 3. 삭제 및 결과 출력
    printf("삽입(i), 삭제(d): d\n");
    e = delete_heap(heap);
    printf("제일 우선순위가 높은 일은 \"%s\"\n", e.list);

    free(heap);
    return 0;
}