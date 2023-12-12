#include <stdio.h>
#include <stdlib.h>

int q[100];
int front = -1, rear = -1;
int size;

void enQueue(int ele)
{
    if ((front == 0) && (rear == (size - 1)) || front == (rear++ % size))
    {
        printf("Queue is full");
    }
    else if (front == rear == -1)
    {
        rear = (rear++) % size;
        front++;
        q[rear] = ele;
    }
    else
    {
        rear = (rear++) % size;
        q[rear] = ele;
    }
}

int main()
{

    return 0;
}