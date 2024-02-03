#include <stdio.h>
#include <stdlib.h>
#include "random.h"
#include "swap.h"

struct Honeypot
{
    char name[100];
    int ip[8];
};

void quickSort(int *a, int first, int last)
{
    int pivot, i, j;
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (a[i] <= a[pivot] && i < last)
            {
                i++;
            }
            while (a[j] > a[pivot])
            {
                j--;
            }
            if (i < j)
            {
                swapVal(&a[i], &a[j]);
            }
        }
        // temp = a[pivot];
        // a[pivot] = a[j];
        // a[j] = temp;
        swapVal(&a[pivot], &a[j]);
        quickSort(a, first, j - 1);
        quickSort(a, j + 1, last);
    }
}

void writeToFile(FILE *fp, int n)
{
    fp = fopen("/home/punith/usr-local/02-sem/dsa-c/lab/06lab/val.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening the file");
        return -1;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "%d\n", generateRandom());
        }
        fclose(fp);
    }
}

void readFromFile(FILE *fp, int n, struct Honeypot honeypot[])
{
    fp = fopen("/home/punith/usr-local/02-sem/dsa-c/lab/06lab/val.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening the file");
        return -1;
    }
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &honeypot[i].ip);

        // fscanf(fp, "%d\n", &);
    }
    fclose(fp);
}

void display(struct Honeypot honeypot[], int n)
{
    printf("Honeypots on the network\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", honeypot[i].name);
        for (int j = 0; j < 10; i++)
        {
            printf("%d", &honeypot[i].ip[j]);
        }
    }
}

void readData(struct Honeypot honeypot[], int n)
{
    int temp;
    printf("Honeypot name and ip\n");
    for (int i = 0; i < n; i++)
    {
        printf("Honeypot name\t");
        scanf("%s", honeypot[i].name);
        printf("Honeypot IP\t");
        for (int j = 0; j < 8; j++)
        {
            scanf("%d", &temp);
            honeypot[i].ip[j] = temp;
        }
    }
}

int main()
{
    int n;
    FILE *fp;
    // int choice;
    printf("Enter the number of Honeypots on the network\n");
    scanf("%d", &n);
    struct Honeypot honeypot[n];

    // while (1)
    // {
    //     printf("Enter your choice");
    //     scanf("%d", &choice);
    //     switch (choice)
    //     {
    //     case 1:
    //         readData(honeypot, n);
    //         break;

    //     default:
    //         break;
    //     }
    // }

    // readData(honeypot, n);

    // int a[n];
    writeToFile(&fp, n);
    readFromFile(&fp, n, honeypot);
    display(honeypot, n);

    // display(a, n);
    // quickSort(a, 0, n);
    printf("Sorted elements are\n");
    // display(a, n);

    return 0;
}