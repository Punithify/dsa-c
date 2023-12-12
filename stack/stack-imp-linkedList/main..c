#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *start = NULL;
int top = -1;

struct node *createNode() // creating a node
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    return newNode;
}

void insertNodeEnd() // insertion at end
{
    struct node *temp, *t;
    temp = createNode();
    printf("Enter node data\n");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (start == NULL) // if no node is avilable
    {
        start = temp;
    }
    else // if nodes are avilable
    {
        t = start;
        while (t->link != NULL) // iterate until we reach the last node
        {
            t = t->link;
        }
        t->link = temp;
    }
}

void deleteAtEnd()
{
    struct node *r, *r1;
    if (start == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    else
    {

        r = start;
        if (r->link == NULL)
        {
            printf("%d", r->data);
            start = NULL;
            return;
        }
        r1 = r->link;
        while (r1->link != NULL)
        {
            r = r1;
            r1 = r1->link;
        }
        r->link = NULL;
        free(r1);
    }
}

void displayList() // traversal
{

    struct node *newPtr;
    if (start == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        newPtr = start;
        while (newPtr != NULL)
        {
            printf("%d \t", newPtr->data);
            newPtr = newPtr->link;
        }
    }
}

int main()
{

    int choice;

    while (1)
    {
        printf("\n1. Enter a new element to the stack");
        printf("\n2. delete from the stack\n");

        printf("3. View Stack\n");
        printf("4. Exit\n");

        printf("Enter choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertNodeEnd();
            break;
        case 2:
            deleteAtEnd();
            break;
        case 3:
            displayList();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice");
        }
    }

    return 0;
}
