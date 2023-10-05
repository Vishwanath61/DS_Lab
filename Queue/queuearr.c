#include<stdio.h>

void create(int q[],int *front,int *rear)
{
    int num;
    printf("\nEnter a number: ");
    scanf("%d",&num);
    ++(*front);
    q[(*front)]=num;
    ++(*rear);
    printf("\nQueue is Created.!!!!!!!!!!!!!!\n");
}

void dequeue(int q[],int *front,int *rear)
{
    int a,b,i;
    a=*front;
    b=*rear;
    printf("\nThe value %d is deleted from the queue.",q[a]);
    for(i=a;i<b;i++)
    {
        q[i]=q[i+1];
    }
    (*rear)--;
}

void enqueue(int q[],int *rear)
{
    int num;
    printf("\nEnter the number to insert: ");
    scanf("%d",&num);
    q[++(*rear)]=num;
}

void peek(int q[],int front)
{
    if(front==-1)
    {
        printf("\nStack is empty.");
    }
    else
    {
        printf("\nThe peek value of the queue is: %d",q[front]);
    }
}

void displayrear(int q[],int rear)
{
    if(rear==-1)
    {
        printf("\nStack is empty.");
    }
    else
    {
        printf("\nThe rear value of the queue is: %d",q[rear]);
    }
}

void displayall(int q[],int front,int rear)
{
    int i;
    for(i=rear;i>=front;i--)
    {
        printf("\n%d",q[i]);
    }
}

void isempty(int q[],int front,int rear)
{
    if(front==-1||rear==-1)
    {
        printf("\nQueue is empty.");
    }
    else
    {
        printf("\nThe queue has some values.");
    }
    
}

void isfull(int q[],int rear,int n)
{
    if(rear==n-1)
    {
        printf("\nQ is full");
    }
    else
    {
        printf("\nThe queue has some space.");
    }
}

void main()
{
    int n=20;
    int queue[n];
    int front=-1,rear=-1;
    int choice;
    create(queue,&front,&rear);
    do
    {
        printf("\n\n1.Enqueue \n2.Dequeue \n3.DisplayAll \n4.DisplayPeek \n5.DisplayRear \n6.IsEmpty \n7.IsFull \n8.Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                enqueue(queue,&rear);
                break;
            }
            case 2:
            {
                dequeue(queue,&front,&rear);
                break;
            }
            case 3:
            {
                displayall(queue,front,rear);
                break;
            }
            case 4:
            {
                peek(queue,front);
                break;
            }
            case 5:
            {
                displayrear(queue,rear);
                break;
            }
            case 6:
            {
                isempty(queue,front,rear);
                break;
            }
            case 7:
            {
                isfull(queue,front,n);
                break;
            }
        }
    }while(choice!=8);
    printf("\nExiting the program....");
}



