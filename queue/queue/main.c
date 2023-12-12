// queue imp using array
#include <stdio.h>
#include <stdlib.h>

int q[100];
int front = -1, rear = -1;
int size;

void enQueue(int ele)
{
    if (rear >= (size - 1))
    {
        printf("Queue is full");
    }
    else if ((rear = = front) == -1)
    {
        front++;
        rear++;
        q[rear] = ele;
    }
    else
    {
        rear++;
        q[rear] = ele;
    }
}

void deQueue()
{
    if ((rear == front) == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("element is :%d\t", q[front]);
        front++;
    }
}

void display()
{
    // int r = 0;
    if (front == -1)
    {
        printf("Queue is empty");
    }
    while (front == (size - 1))
    {
        printf("%d\t", q[front]);
        front++;
    }
}

int main()
{
    printf("Enter size of the queue");
    scanf("%d", &size);
    enQueue(12);
    display();
    return 0;
}
