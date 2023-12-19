#include <stdio.h>
#include <stdlib.h>
#include "pot.h"

struct Node *front = NULL;
struct Node *rear = NULL;

void initQueue()
{
    front = rear = NULL;
}

int isEmpty()
{
    return (front == NULL);
}

void enqueue(struct Honeypot honeypot)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = honeypot;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

struct Honeypot dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(1);
    }

    struct Node *temp = front;
    struct Honeypot data = temp->data;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }

    free(temp);
    return data;
}

struct Honeypot peek()
{
    if (isEmpty())
    {
        printf("Queue is empty. Cannot peek.\n");
        exit(1);
    }

    return front->data;
}

void displayQueue()
{
    struct Node *temp = front;

    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL)
    {
        printf("(%d - %s) ", temp->data.id, temp->data.name);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    initQueue();
    int choice, numHoneypots, HoneypotId;
    struct Honeypot honeypot;

    do
    {
        printf("\nCloth Shop Management System\n");
        printf("1. Add Honeypot\n");
        printf("2. Display Queue\n");
        printf("3. Remove Honeypot\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of Honeypots to add: ");
            scanf("%d", &numHoneypots);
            for (int i = 0; i < numHoneypots; ++i)
            {
                printf("Enter Honeypot ID: ");
                scanf("%d", &honeypot.id);
                printf("Enter Honeypot name: ");
                scanf("%s", honeypot.name);
                enqueue(honeypot);
                printf("Honeypot %d added to the queue.\n", honeypot.id);
            }
            break;
        case 2:
            printf("Current Queue:\n");
            displayQueue();
            break;
        case 3:
            if (!isEmpty())
            {
                printf("Enter Honeypot ID to remove: ");
                scanf("%d", &HoneypotId);
                struct Honeypot removedHoneypot;
                struct Node *temp = NULL;
                int found = 0;

                while (!isEmpty())
                {
                    removedHoneypot = dequeue();
                    if (removedHoneypot.id == HoneypotId)
                    {
                        printf("Honeypot (%d - %s) removed from the queue.\n", removedHoneypot.id, removedHoneypot.name);
                        found = 1;
                        break;
                    }
                    else
                    {
                        // Store other Honeypots temporarily
                        if (temp == NULL)
                        {
                            temp = (struct Node *)malloc(sizeof(struct Node));
                            temp->data = removedHoneypot;
                            temp->next = NULL;
                        }
                        else
                        {
                            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                            newNode->data = removedHoneypot;
                            newNode->next = NULL;

                            struct Node *iter = temp;
                            while (iter->next != NULL)
                            {
                                iter = iter->next;
                            }
                            iter->next = newNode;
                        }
                    }
                }

                // Re-add other Honeypots back to the queue
                while (temp != NULL)
                {
                    enqueue(temp->data);
                    struct Node *toFree = temp;
                    temp = temp->next;
                    free(toFree);
                }

                if (!found)
                {
                    printf("Honeypot ID not found in the queue.\n");
                }
            }
            else
            {
                printf("Queue is empty. Cannot remove.\n");
            }
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
