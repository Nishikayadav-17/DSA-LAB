#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next) temp = temp->next;

    temp->next = newNode;
    return head;
}

// move zeroes to front
void Zeroes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp) {
        if (temp->data == 0) count++;
        temp = temp->next;
    }

    temp = head;

    while (count--) {
        temp->data = 0;
        temp = temp->next;
    }

    struct Node* curr = head;
    while (curr) {
        if (curr->data != 0) {
            temp->data = curr->data;
            temp = temp->next;
        }
        curr = curr->next;
    }
}

// display
void display(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, x;

    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    display(head);

    Zeroes(head);

    display(head);

    return 0;
}