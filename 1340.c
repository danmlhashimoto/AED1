#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000

typedef struct {
    int data[MAXN];
    int size;
} PriorityQueue;

void pq_init(PriorityQueue *pq) {
    pq->size = 0;
}

void pq_push(PriorityQueue *pq, int x) {
    pq->data[pq->size] = x;
    int i = pq->size++;
    while (i > 0 && pq->data[i] > pq->data[(i - 1) / 2]) {
        int temp = pq->data[i];
        pq->data[i] = pq->data[(i - 1) / 2];
        pq->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int pq_pop(PriorityQueue *pq) {
    if (pq->size == 0) return -1;
    int root = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    int i = 0;
    while (2 * i + 1 < pq->size) {
        int j = 2 * i + 1;
        if (j + 1 < pq->size && pq->data[j] < pq->data[j + 1]) {
            j++;
        }
        if (pq->data[i] >= pq->data[j]) break;
        int temp = pq->data[i];
        pq->data[i] = pq->data[j];
        pq->data[j] = temp;
        i = j;
    }
    return root;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int stack[MAXN], queue[MAXN], queue_head = 0, stack_top = -1;
        PriorityQueue pq;
        pq_init(&pq);

        bool is_stack = true, is_queue = true, is_pq = true;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d", &x);
                if (is_stack) stack[++stack_top] = x;
                if (is_queue) queue[queue_head++] = x;
                if (is_pq) pq_push(&pq, x);
            } else if (op == 2) {
                scanf("%d", &x);
                if (is_stack) {
                    if (stack_top >= 0 && stack[stack_top] == x) {
                        stack_top--;
                    } else {
                        is_stack = false;
                    }
                }
                if (is_queue) {
                    if (queue_head > 0 && queue[0] == x) {
                        for (int j = 1; j < queue_head; j++) {
                            queue[j - 1] = queue[j];
                        }
                        queue_head--;
                    } else {
                        is_queue = false;
                    }
                }
                if (is_pq) {
                    if (pq.size > 0 && pq.data[0] == x) {
                        pq_pop(&pq);
                    } else {
                        is_pq = false;
                    }
                }
            }
        }
        
        if (is_stack + is_queue + is_pq > 1) {
            printf("not sure\n");
        } else if (is_stack) {
            printf("stack\n");
        } else if (is_queue) {
            printf("queue\n");
        } else if (is_pq) {
            printf("priority queue\n");
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}
