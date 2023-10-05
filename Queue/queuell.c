#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

void createqueue(struct queue **front,struct queue **rear)
{
    printf("\n\n*******Creating a Queue*******");
    int num,n;
    printf("\n\nEnter no. of elements in the queue: ");
    scanf("%d",&n);
    printf("\nEnter the data: ");
    scanf("%d",&num);
    *front=malloc(sizeof(struct queue));
    (*front)->data=num;
    (*front)->next=NULL;
    n--;
    *rear=*front;
    while(n!=0)
    {
        printf("Enter the data: ");
        scanf("%d",&num);
        (*rear)->next=malloc(sizeof(struct queue));
        *rear=(*rear)->next;
        (*rear)->data=num;
        n--;
    }
    (*rear)->next=NULL;
}

void displayqueue(struct queue *front)
{
    printf("\n\n*******Displaying the Queue*******");
    while(front!=NULL)
    {
        printf("\n%d",front->data);
        front=front->next;
    }
}

void enqueue(struct queue **rear)
{
    int num;
    printf("\n\nEnter the number you need to enqueue: ");
    scanf("%d",&num);
    (*rear)->next=malloc(sizeof(struct queue));
    *rear=(*rear)->next;
    (*rear)->data=num;
    (*rear)->next=NULL;
    printf("Successfully enqueued....");
}

void dequeue(struct queue **front)
{
    struct queue *temp;
    temp=*front;
    *front=(*front)->next;
    free(temp);
    printf("\n\nSuccessfully dequeued....");
}

void isemptyqueue(struct queue *front,struct queue *rear)
{
    if((front==NULL)&&(rear==NULL))
    {
        printf("\nThe Queue is Empty.");
    }
}

void displayrear(struct queue *rear)
{
    printf("\n\nThe Rear value of the queue is: %d",rear->data);
}

void main()
{
    struct queue *front=NULL;
    struct queue *rear=NULL;
    isemptyqueue(front,rear);
    createqueue(&front,&rear);
    displayqueue(front);
    enqueue(&rear);
    displayqueue(front);
    dequeue(&front);
    displayqueue(front);
    displayrear(rear);
}
