#include <stdio.h>
#include <stdlib.h>
#include "search.h"

int a[10];
int n;

void display()
{
    printf("Elements are\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}

void linearSearch()
{
    int eleCmp = 0, indexCmp = 0;

    int searchElement;
    printf("Enter the element to be searched\n");
    scanf("%d", &searchElement);
    for (int i = 0; i < n; i++)
    {
        indexCmp++;

        if (a[i] == searchElement)
        {
            eleCmp++;

            printf("Element found is %d at %d\n", a[i], i);
            printf("Number of index and element comparisons %d  %d\n", indexCmp + 1, eleCmp);
        }
    }
}

void sentielSearch()
{ // only element comparsions are performed
    int eleCmp = 0;

    int searchElement;
    printf("Enter the element to be searched\t");
    scanf("%d", &searchElement);
    int i = 0;
    while (a[i] != searchElement)
        eleCmp++;
    {
        i++;
    }
    if (i < n)
    {
        printf("Element found\n");
    }
    else
    {
        printf("element not found\n");
    }
    printf("Number of element comparisons %d  %d\n", eleCmp);
}

void binarySearch()
{
    int eleCmp = 0, indexCmp = 0;

    int searchElement;
    printf("Enter the element to be searched\t");
    scanf("%d", &searchElement);
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        indexCmp++;
        int middle = low + (high - low) / 2;
        if (a[middle] == searchElement)
        {
            printf("Element found at position %d\n", middle);
        }
        if (a[middle] < searchElement)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
        // printf("Element not found\n");
    }
    printf("Number of index and element comparisons %d  %d\n", indexCmp, eleCmp);
}

void insertionSort()
{
    int eleCmp = 0, indexCmp = 0;

    int key, i = 0;
    for (int j = 1; j < n; j++)
    {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;
    }
    display();
}

void bubbleSort()
{
    int eleCmp = 0, indexCmp = 0;
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    display();
}

int main()
{

    int choice, searchElement;
    printf("Enter size of the array\n");
    scanf("%d", &n);
    printf("Enter elements\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // while (1)
    // {
    //     printf("1. Display Elements\n");
    //     printf("2. Linear Search\n");
    //     printf("3. Sentiel Search\n");
    //     printf("4. Bineary Search\n");
    //     printf("5. Insertion Sort\n");
    //     printf("6. Bubble  Sort\n");
    //     printf("7. Exit\n");
    //     printf("Enter choice\t");
    //     scanf("%d", &choice);
    //     switch (choice)
    //     {
    //     case 1:
    //         display();
    //         break;
    //     case 2:
    //         linearSearch();
    //         break;
    //     case 3:
    //         sentielSearch();
    //         break;
    //     case 4:
    //         binarySearch();
    //         break;
    //     case 5:
    //         insertionSort();
    //         break;
    //     case 6:
    //         bubbleSort();
    //         break;
    //     default:
    //         break;
    //     }
    // }
    printf("Enter the search element\n");
    scanf("%d", &searchElement);
    int res = linearSearch(a, searchElement);
    printf("%d", &res);
    return 0;
}