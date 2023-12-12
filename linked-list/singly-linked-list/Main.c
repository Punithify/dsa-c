// linked list and its operations

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *start = NULL;

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

void deleteBegining()
{
    struct node *r;
    if (start == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    else
    {
        r = start;
        start = start->link;
        free(r);
    }
}

void displayList() // traversal
{

    struct node *newPtr;
    if (start == NULL)
    {
        printf("Linked is empty\n");
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

void insertAtPosition()
{
    struct node *t, *t1, *temp;
    int count = 1, pos, val;
    printf("Enter the position");
    scanf("%d", &pos);
    if (start == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    else
    {
        t = start;
        t1 = t->link;
        while (count < (pos - 1))
        {
            t = t1;
            t1 = t1->link;
            count++;
        }
        // t1 = t;
        temp = createNode();
        printf("Enter data to be inserted\n");
        scanf("%d", &val);
        t->link = temp;
        temp->link = t1;
        temp->data = val;
    }
}

void deleteAtPosition()
{
    struct node *t, *t1;
    int count, pos;
    printf("Enter the position to be deleted");
    scanf("%d", &pos);
    if (start == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    else
    {
        t = start;
        t1 = t->link;
        while (count < (pos - 1))
        {
            t = t1;
            t1 = t1->link;
            count++;
        }
        t->link = t1->link;
        t1->link = NULL;
        free(t1);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Enter a new node to the Linked List\n");
        printf("2. Delete the first node\n");
        printf("3. View the linked List\n");
        printf("4. Insert at a given position\n");
        printf("5. Delete at a given position\n");
        printf("6. Exit\n");

        printf("Enter choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertNodeEnd();
            break;
        case 2:
            deleteBegining();
            break;
        case 3:
            displayList();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteAtPosition();
            break;
        case 6:
            exit(0);

        default:
            printf("Invalid choice");
        }
    }

    return 0;
}