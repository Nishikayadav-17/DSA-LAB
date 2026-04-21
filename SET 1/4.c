/*Delete the first node.
Delete the last node.*/

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

// Delete first node 
struct Node* deleteFirst(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

// Delete last node 
struct Node* deleteLast(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

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
    head->next->next->next = NULL;

    printf("Original List:\n");
    display(head);

    head = deleteFirst(head);
    printf("\nAfter deleting first node:\n");
    display(head);

    head = deleteLast(head);
    printf("\nAfter deleting last node:\n");
    display(head);

    return 0;
}