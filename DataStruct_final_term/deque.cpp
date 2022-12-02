#include"deque.h"


// 오류 함수
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
// 초기화
void init_deque(DequeType* q)
{
    q->front = q->rear = 0;
}

int que_is_empty(DequeType* q)
{
    return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(DequeType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 원형큐 출력 함수
/*void deque_print(DequeType* q)
{
    printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!que_is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}*/

void add_rear(DequeType* q, element item)
{
    if (is_full(q))
        error((char*)"큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}
void add_front(DequeType* q, element val)
{
    if (is_full(q))
        error((char*)"큐가 포화상태입니다");
    q->data[q->front] = val;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_front(DequeType* q)
{
    if (que_is_empty(q))
        error((char*)"큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}
element delete_rear(DequeType* q)
{
    int prev = q->rear;
    if (que_is_empty(q))
        error((char*)"큐가 공백상태입니다");
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return q->data[prev];
}

element get_front(DequeType* q)
{
    if (que_is_empty(q))
        error((char*)"큐가 공백상태입니다");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
element get_rear(DequeType* q)
{
    if (que_is_empty(q))
        error((char*)"큐가 공백상태입니다");
    return q->data[q->rear];
}