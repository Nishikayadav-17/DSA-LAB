// Stack using linked list

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct stack
{
    struct node *top;
};

void push(struct stack *stack,int element)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=element;
    newnode->next=stack->top;
    stack->top=newnode;
}
int pop(struct stack *stack)
{
    if(stack->top==NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
    struct node *temp=stack->top;
    int popped=temp->data;
    stack->top=temp->next;
    free (temp);
    return popped;
    }
}
int peek(struct stack* stack) 
{
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}
int check_empty(struct stack *stack)
{
    if(stack->top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display(struct stack *stack)
{
    if(stack->top==NULL)
    {
        printf("Empty stack\n");
        return;
    }
    else
    {
        struct node *temp=stack->top;
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
            printf("\n");
        }
    }
}
int main()
{
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top=NULL;
    int choice, value;

    while (1) 
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Check Empty\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(s, value);
                break;
            case 2:
                value = pop(s);
                if (value != -1)
                    printf("Popped: %d\n", value);
                break;
            case 3:
                value = peek(s);
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;
            case 4:
                if (check_empty(s))
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 5:
                display(s);
                break;
                case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
stack using link