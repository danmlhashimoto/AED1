#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 1000000

typedef struct {
    int stack[MAX_N];
    int min_stack[MAX_N];
    int top;
    int min_top;
} MagicBag;

void init(MagicBag *bag) {
    bag->top = -1;
    bag->min_top = -1;
}

void push(MagicBag *bag, int value) {
    bag->stack[++(bag->top)] = value;
    if (bag->min_top == -1 || value <= bag->min_stack[bag->min_top]) {
        bag->min_stack[++(bag->min_top)] = value;
    }
}

void pop(MagicBag *bag) {
    if (bag->top == -1) {
        printf("EMPTY\n");
        return;
    }
    if (bag->stack[bag->top] == bag->min_stack[bag->min_top]) {
        bag->min_top--;
    }
    bag->top--;
}

void get_min(MagicBag *bag) {
    if (bag->min_top == -1) {
        printf("EMPTY\n");
    } else {
        printf("%d\n", bag->min_stack[bag->min_top]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    MagicBag bag;
    init(&bag);

    char command[10];
    int value;
    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        if (command[0] == 'P' && command[1] == 'U') { // PUSH
            scanf("%d", &value);
            push(&bag, value);
        } else if (command[0] == 'P' && command[1] == 'O') { // POP
            pop(&bag);
        } else if (command[0] == 'M') { // MIN
            get_min(&bag);
        }
    }
    return 0;
}
