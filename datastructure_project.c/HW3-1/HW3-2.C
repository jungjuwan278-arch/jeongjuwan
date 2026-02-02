#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DEQUEUE_MAX_SIZE 100
typedef char element;

typedef struct {
    element Dequeue[DEQUEUE_MAX_SIZE];
    int front, rear;
} Dequeuetype;

void init(Dequeuetype* q) {
    q->front = q->rear = 0;
}

bool is_full(Dequeuetype* q) {
    return ((q->rear + 1) % DEQUEUE_MAX_SIZE == q->front);
}

bool is_empty(Dequeuetype* q) {
    return q->front == q->rear;
}

void push_back(Dequeuetype* q, element item) {
    if (is_full(q)) exit(1);
    q->rear = (q->rear + 1) % DEQUEUE_MAX_SIZE;
    q->Dequeue[q->rear] = item;
}

void push_front(Dequeuetype* q, element item) {
    if (is_full(q)) exit(1);
    q->Dequeue[q->front] = item;
    // 음수 방지를 위해 MAX_SIZE를 더한 후 나머지 연산 수행
    q->front = (q->front - 1 + DEQUEUE_MAX_SIZE) % DEQUEUE_MAX_SIZE;
}

element pop_front(Dequeuetype* q) {
    if (is_empty(q)) exit(1);
    q->front = (q->front + 1) % DEQUEUE_MAX_SIZE;
    return q->Dequeue[q->front];
}

element pop_back(Dequeuetype* q) {
    if (is_empty(q)) exit(1);
    element temp = q->Dequeue[q->rear];
    q->rear = (q->rear - 1 + DEQUEUE_MAX_SIZE) % DEQUEUE_MAX_SIZE;
    return temp;
}

// 요소 개수를 반환
int get_count(Dequeuetype* q) {
    if (q->front <= q->rear)
        return q->rear - q->front;
    else
        return DEQUEUE_MAX_SIZE - (q->front - q->rear);
}

void check_palindrome(char I[]) {
    Dequeuetype q;
    init(&q);
    int i = 0;
    
    while (I[i] != '\0') {
        if (I[i] >= 'a' && I[i] <= 'z') push_back(&q, I[i]);
        else if (I[i] >= 'A' && I[i] <= 'Z') push_back(&q, I[i] + ('a' - 'A'));
        i++;
    }

    // get_count를 활용하여 요소가 2개 이상일 때만 비교 반복
    while (get_count(&q) > 1) {
        if (pop_front(&q) != pop_back(&q)) {
            printf("%s: Palindrome이 아닙니다.\n", I);
            return;
        }
    }
    printf("%s: Palindrome이 맞습니다.\n", I);
}

int main(void) {
    char I[20] = "madam";
    char T[20] = "radar";
    check_palindrome(I);
    check_palindrome(T);
    return 0;
}