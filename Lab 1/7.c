#include <stdio.h>
#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void init(struct Stack *s) {
    s->top = -1;
}

// Check if empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Check if full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Push operation
void push(struct Stack *s, int x) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = x;
}

// Pop operation
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->arr[(s->top)--];
}

// Queue using two stacks
struct Stack s1, s2;

// Enqueue
void enqueue(int x) {
    push(&s1, x);
}

// Dequeue
int dequeue() {
    if (isEmpty(&s2)) {
        while (!isEmpty(&s1)) {
            push(&s2, pop(&s1));
        }
    }

    if (isEmpty(&s2)) {
        printf("Queue is empty\n");
        return -1;
    }

    return pop(&s2);
}

// Display queue
void display() {
    // Elements in s2 (correct order)
    for (int i = s2.top; i >= 0; i--) {
        printf("%d ", s2.arr[i]);
    }

    // Elements in s1 (reverse order)
    for (int i = 0; i <= s1.top; i++) {
        printf("%d ", s1.arr[i]);
    }

    printf("\n");
}

// Main function
int main() {
    init(&s1);
    init(&s2);

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Dequeued: %d\n", dequeue());

    enqueue(40);

    printf("Queue elements: ");
    display();

    return 0;
}