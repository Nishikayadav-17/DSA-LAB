// Stack using array

#include<stdio.h>
#include<stdlib.h>
void push(int stack[],int n,int *top,int element)
{
    if(*(top)==n-1)
    {
        printf("Overflow.\n");
        return;
    }
    else
    {
       (*top)++;
       stack[*(top)]=element;
       printf("%d pushed to stack.\n", element);
    }
}
int  pop(int stack[],int n,int *top)
{
    int item;
    if((*top)==-1)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        item=stack[*(top)];
        printf("Popped element from stack:%d",stack[*(top)]);
        (*top)--;
    }
    return item;
    
}
void print(int stack[],int top)
{
    if(top==-1)
    {
        printf("Empty stack\n");
        return;
    }
    else
    {
        int i;
        for(i=top;i>=0;i--)
        {
            printf("%d",stack[i]);
            printf("\n");
        }
    }
}
void peek(int stack[],int top)
{
    if(top==-1)
    {
        printf("Empty stack.\n");
    }


    printf("Element is: %d",stack[top]);
}
int main()
{
    int n,i;
    printf("Enter the range of the array:\n");
    scanf("%d",&n);
    int *stack=(int*)malloc(n*sizeof(int));
    int top=-1;
    int item;
    int choice;
    while(1)
    {
    printf("Enter the number for the following operations:\n1-Push\n2-Pop\n3-Display\n4-Peek\n5-Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Enter the element to be pushed:\n");
        int y;
        scanf("%d",&y);
        push(stack,n,&top,y);
        break;
        case 2:
        item=pop(stack,n,&top);
        printf("Popped element :%d:\n",item);
        break;
        case 3:
        print(stack,top);
        break;
        case 4:
        peek(stack,top);
        break;
        case 5:
        printf("Exiting the program...\n");
        return 0;
        break;
        default:
        printf("Invalid position.\nEnter the number between (1-4) only\n");
    }
  }
}