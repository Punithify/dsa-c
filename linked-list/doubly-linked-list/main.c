#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *front = NULL;
struct node *last = NULL;

struct node *createNode()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // creating a node n
    return newNode;
}

void insertNodeEnd() // insertion at end
{
    struct node *newNode, *temp;
    newNode = createNode();
    printf("Enter data to be inserted\n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (front == NULL)
    {
        newNode->prev = NULL;
        front = last = newNode; // front and last will point to the new node
    }
    else
    {
        temp = front;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
        last = newNode;
        newNode->next = NULL;
    }
}

void forwardDisplay()
{
    struct node *temp;
    temp = front;
    printf("Doubly linked items are :\n");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void insertInBetween()
{
    struct node *t, *t1, *newNode;
    int count = 1, pos, val;
    printf("Enter the position");
    scanf("%d", &pos);
    if (front == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    else
    {
        t = front;
        t1 = t->next;
        while (count < (pos - 1))
        {
            t = t1;
            t1 = t1->next;
            count++;
        }
        newNode = createNode();
        printf("Enter data to be inserted\n");
        scanf("%d", &val);
        t->next = newNode;
        newNode->prev = t;
        newNode->next = t1;
        t1->prev = newNode;
        newNode->data = val;
    }
}

int main()
{

    int choice;

    while (1)
    {
        printf("\n1. Enter a new node to the Doubly Linked List(at end)\n");
        printf("2. View the linked List \n");
        // printf("3.\n");
        printf("3. Insert at a given position\n");
        // printf("5. Delete at a given position\n");
        printf("4. Exit\n");

        printf("Enter choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertNodeEnd();
            break;
        case 2:
            if (front != NULL)
            {
                forwardDisplay();
            }
            break;
        case 3:
            insertInBetween();
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
