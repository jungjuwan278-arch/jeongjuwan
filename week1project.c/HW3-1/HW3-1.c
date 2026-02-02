#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10  // 큐의 크기

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// 큐 초기화
void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

// 공백 상태 검출
int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

// 포화 상태 검출
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 연산
void enqueue(QueueType* q, element item) {
    if (is_full(q)) {
        printf("큐가 포화상태입니다.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 삭제 연산
element dequeue(QueueType* q) {
    if (is_empty(q)) {
        printf("큐가 공백상태입니다.\n");
        return -1;
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// 요소의 개수를 반환하는 연산
int get_count(QueueType* q) {
    if (q->front <= q->rear) {
        return q->rear - q->front;
    } else {
        return MAX_QUEUE_SIZE - (q->front - q->rear);
    }
}

int main() {
    QueueType q;
    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    
    printf(": %d\n", get_count(&q)); // 3 출력

    dequeue(&q);
    printf(": %d\n", get_count(&q)); // 2 출력

    return 0;
}