// Delete a node with a given value.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* deleteByValue(struct Node *head, int value) {
    struct Node *temp = head, *prev = NULL;

    // Case 1: Empty list 
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    // Case 2: First node contains value
    if (head->data == value) {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in list.\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

int main() {
    struct Node *head = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;

    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;

    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 30;

    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = 40;
    head->next->next->next->next = NULL;

    printf("Original List:\n");
    display(head);

    head = deleteByValue(head, 30);

    printf("\nAfter deleting 30:\n");
    display(head);

    return 0;
}