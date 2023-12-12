#include <stdio.h>
#include <stdlib.h>

int a[100];
int size, top = -1;

void push()
{
    int ele;
    if (top == (size - 1))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter element\n");
        scanf("%d", &ele);
        top++;
        a[top] = ele;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        printf("deleted item is : %d\t", a[top]);
        top--;
    }
}

void displayStack()
{
    int i;
    if (top != -1)
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d\t", a[i]);
        }
    }
}

int main()
{

    printf("enter size of stack\n");
    scanf("%d", &size);

    int choice;

    while (1)
    {
        printf("\n1. Push \n");
        printf("2. Pop\n");
        printf("3. View Stack\n");
        printf("4. Exit\n");

        printf("Enter choice\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            displayStack();
            break;
        case 4:
            exit(0);

        default:
            printf("Invalid choice");
        }
    }

    return 0;
}