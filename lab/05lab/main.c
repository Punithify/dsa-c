#include <stdio.h>
#include <stdlib.h>

int a[10];
int n;
int eleCmp = 0, indexCmp = 0;

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
    int searchElement;
    printf("Enter the element to be searched\n");
    scanf("%d", &searchElement);

    for (int i = 0; i < n; i++)
    {
        indexCmp++;
        eleCmp++;

        if (a[i] == searchElement)
        {
            printf("Element found is %d at %d\n", a[i], i);
            printf("Number of index and element comparisons %d  %d\n", indexCmp, eleCmp);
        }
    }
}

void sentielSearch()
{ // only element comparsions are performed

    int searchElement;
    printf("Enter the element to be searched\n");
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
}

void binarySearch()
{
    int searchElement;
    printf("Enter the element to be searched\n");
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
}

void insertionSort()
{
    int key, i = 0;
    for (int j = 0; j < n; j++)
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

    printf("Enter size of the array\n");
    scanf("%d", &n);
    printf("Enter elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // linearSearch();
    // sentielSearch();
    // binarySearch();
    // insertionSort();
    bubbleSort();
    return 0;
}