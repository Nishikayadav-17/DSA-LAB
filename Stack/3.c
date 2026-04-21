// Double stack

#include<stdio.h>
void push1(int array[],int *top1,int *top2,int item)
{
    if((*top1+1)==*top2)
    {
        printf("Stack overflow\n");
        return;
    }
    (*top1)++;
    array[*top1]=item;
}
void push2(int array[],int *top1,int *top2,int item)
{
    if((*top1+1)==*top2)
    {
        printf("Stack overflow\n");
        return;
    }
    (*top2)--;
    array[*top2]=item;
}
int pop1(int array[],int *top1,int *top2)
{
    if(*top1==-1)
    {
        printf("Underflow\n");
        return -1000;
    }
    int popped=array[*top1];
    array[*top1] = -1;
    (*top1)--;
    return popped;
}
int pop2(int array[],int *top1,int *top2,int n)
{
    if(*top2==n)
    {
        printf("Underflow\n");
        return -1000;
    }
    int popped=array[*top2];
     array[*top2] = -1;
    (*top2)++;
    return popped;
}
void display(int array[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%3d",array[i]);
    }
    printf("\n");
}

int main()
{
int n,i;
    printf("Enter the range of the array:\n");
    scanf("%d",&n);
    int top1=-1;
    int top2=n;
    int array[n];
    for(int i=0;i<n;i++)
    {
    array[i]=-1;
    }
    push1(array,&top1,&top2,10);
    push1(array,&top1,&top2,20);
    push2(array,&top1,&top2,30);
    push2(array,&top1,&top2,40);

    display(array,n);

    printf("Pop from Stack1: %d\n", pop1(array,&top1,&top2));
    printf("Pop from Stack2: %d\n", pop2(array,&top1,&top2,n));

    display(array,n);

    return 0;
}