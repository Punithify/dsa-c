#include <stdio.h>
#include <string.h>

#define MAX_HONEYPOTS 100

struct Honeypot
{
    int honeypotId;
    char name[50];
    float port;
};

struct Honeypot Honeypots[MAX_HONEYPOTS];
int numHoneypots = 0;

void insertHoneypot();
void deleteHoneypot(int honeypotId);
int linearSearchHoneypot(int honeypotId);
void displayHoneypots();
// matrix
void addMatrix(float matrix1[][2], float matrix2[][2], float result[][2]);
void subtractMatrix(float matrix1[][2], float matrix2[][2], float result[][2]);

int main()
{
    int i, j;
    int choice;
    int honeypotId;
    int searchResult;
    float matrix1[2][2] = {{192.0, 168.0}, {0.0, 1.0}};
    float matrix2[2][2] = {{192.0, 168.0}, {0.0, 5.0}};
    float resultMatrix[2][2];

    do
    {
        printf("\nHoneypot Network Menu:\n");
        printf("1. Insert honeypot to the network\n");
        printf("2. Delete honeypot from the network\n");
        printf("3. Search honeypot in the network\n");
        printf("4. Display honeypot on the network\n");
        printf("5. Add Matrices\n");
        printf("6. Subtract Matrices\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertHoneypot();
            break;
        case 2:
            printf("Enter Honeypot ID to delete: ");
            scanf("%d", &honeypotId);
            deleteHoneypot(honeypotId);
            break;
        case 3:
            printf("Enter Honeypot ID to search: ");
            scanf("%d", &honeypotId);
            searchResult = linearSearchHoneypot(honeypotId);
            if (searchResult != -1)
            {
                printf("Honeypot found at index %d\n", searchResult);
            }
            else
            {
                printf("Honeypot not found.\n");
            }
            break;
        case 4:
            displayHoneypots();
            break;
        case 5:
            addMatrix(matrix1, matrix2, resultMatrix);
            printf("Result of Matrix Addition:\n");
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                {
                    printf("%.2f\t", resultMatrix[i][j]);
                }
                printf("\n");
            }
            break;
        case 6:
            subtractMatrix(matrix1, matrix2, resultMatrix);
            printf("Result of Matrix Subtraction:\n");
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 2; j++)
                {
                    printf("%.2f\t", resultMatrix[i][j]);
                }
                printf("\n");
            }
            break;
        case 7:
            printf("Exiting program. No Honeypots found!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

void insertHoneypot()
{
    if (numHoneypots < MAX_HONEYPOTS)
    {
        struct Honeypot newHoneypot;
        printf("Enter Honeypot ID: ");
        scanf("%d", &newHoneypot.honeypotId);
        printf("Enter Honeypot Name: ");
        scanf("%s", newHoneypot.name);
        printf("Enter Honeypot port: ");
        scanf("%f", &newHoneypot.port);

        Honeypots[numHoneypots] = newHoneypot;
        numHoneypots++;
        printf("Honeypot inserted successfully!\n");
    }
    else
    {
        printf("Maximum number of Honeypots reached.\n");
    }
}

void deleteHoneypot(int honeypotId)
{
    int i, j;
    for (i = 0; i < numHoneypots; i++)
    {
        if (Honeypots[i].honeypotId == honeypotId)
        {
            for (j = i; j < numHoneypots - 1; j++)
            {
                Honeypots[j] = Honeypots[j + 1];
            }
            numHoneypots--;
            printf("Honeypot with process ID %d deleted successfully!\n", honeypotId);
            return;
        }
    }
    printf("Honeypot with ID %d not found.\n", honeypotId);
}

int linearSearchHoneypot(int honeypotId)
{
    int i;
    for (i = 0; i < numHoneypots; i++)
    {
        if (Honeypots[i].honeypotId == honeypotId)
        {
            return i;
        }
    }
    return -1; // Honeypot not found
}

void displayHoneypots()
{
    int i;
    printf("Honeypot List:\n");
    printf("ID\tName\tPORT\n");
    for (i = 0; i < numHoneypots; i++)
    {
        printf("%d\t%s\t%.2f\n", Honeypots[i].honeypotId, Honeypots[i].name, Honeypots[i].port);
    }
}

void addMatrix(float matrix1[][2], float matrix2[][2], float result[][2])
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrix(float matrix1[][2], float matrix2[][2], float result[][2])
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
