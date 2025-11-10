#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int* items;
    int top;
    int size;
};

void initStack(struct Stack* s, int size) {
    s->items = (int*)malloc(size * sizeof(int));
    s->top = -1;
    s->size = size;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int isFull(struct Stack* s) {
    return s->top == s->size - 1;
}

void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is full! Cannot push %d\n", value);
        return;
    }
    s->top++;
    s->items[s->top] = value;
    printf("Pushed %d\n", value);
}

void pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot pop\n");
        return;
    }
    printf("Popped %d\n", s->items[s->top]);
    s->top--;
}

void peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return;
    }
    printf("Top element is %d\n", s->items[s->top]);
}

int main() {
    int size, choice, value;
    struct Stack s;

    printf("Enter stack size: ");
    scanf("%d", &size);
    initStack(&s, size);

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek(&s);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    free(s.items);
    return 0;
}
