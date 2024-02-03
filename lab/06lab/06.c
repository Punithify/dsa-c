#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Honeypot
{
    int id;
    char name[50];
    double port;
};

void generateRandomData(struct Honeypot arr[], int size)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < size; ++i)
    {
        arr[i].id = i + 1;
        sprintf(arr[i].name, "Honeypot%d", i + 1);
        arr[i].port = rand() % 50; // Generating port
    }
}

void printData(struct Honeypot arr[], int size)
{
    printf("ID\tName\tport\n");
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d\t%s\t%.2f\n", arr[i].id, arr[i].name, arr[i].port);
    }
}

void writeToFile(struct Honeypot arr[], int size, const char *fileName)
{
    FILE *outputFile = fopen(fileName, "w");
    int i;
    for (i = 0; i < size; ++i)
    {
        fprintf(outputFile, "%d\t%s\t%.2f\n", arr[i].id, arr[i].name, arr[i].port);
    }

    fclose(outputFile);
}

void merge(struct Honeypot arr[], int left, int middle, int right, int *indexComparisons, int *elementComparisons)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int i, j;
    struct Honeypot leftArray[n1], rightArray[n2];

    for (i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];

    i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        (*indexComparisons)++;
        if (leftArray[i].port <= rightArray[j].port)
        {
            (*elementComparisons)++;
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            (*elementComparisons)++;
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        (*elementComparisons)++;
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        (*elementComparisons)++;
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(struct Honeypot arr[], int left, int right, int *indexComparisons, int *elementComparisons)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle, indexComparisons, elementComparisons);
        mergeSort(arr, middle + 1, right, indexComparisons, elementComparisons);

        merge(arr, left, middle, right, indexComparisons, elementComparisons);
    }
}

int partition(struct Honeypot arr[], int low, int high, int *indexComparisons, int *elementComparisons)
{
    double pivot = arr[high].port;
    int i = (low - 1);
    int j;
    for (j = low; j <= high - 1; j++)
    {
        (*indexComparisons)++;
        if (arr[j].port <= pivot)
        {
            (*elementComparisons)++;
            i++;
            struct Honeypot temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    struct Honeypot temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(struct Honeypot arr[], int low, int high, int *indexComparisons, int *elementComparisons)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, indexComparisons, elementComparisons);

        quickSort(arr, low, pi - 1, indexComparisons, elementComparisons);
        quickSort(arr, pi + 1, high, indexComparisons, elementComparisons);
    }
}

int main()
{
    const int size = 10;
    struct Honeypot Honeypots[size];

    generateRandomData(Honeypots, size);

    printf("Unsorted Data:\n");
    printData(Honeypots, size);
    printf("\n");

    int mergeIndexComparisons = 0, mergeElementComparisons = 0;
    mergeSort(Honeypots, 0, size - 1, &mergeIndexComparisons, &mergeElementComparisons);

    printf("Data after Merge Sort:\n");
    printData(Honeypots, size);
    printf("Merge Sort Index Comparisons: %d\n", mergeIndexComparisons);
    printf("Merge Sort Element Comparisons: %d\n\n", mergeElementComparisons);

    writeToFile(Honeypots, size, "/home/punith/usr-local/02-sem/dsa-c/lab/06lab/merge_sort_output.txt");

    generateRandomData(Honeypots, size);

    printf("Unsorted Data:\n");
    printData(Honeypots, size);
    printf("\n");

    int quickIndexComparisons = 0, quickElementComparisons = 0;
    quickSort(Honeypots, 0, size - 1, &quickIndexComparisons, &quickElementComparisons);

    printf("Data after Quick Sort:\n");
    printData(Honeypots, size);
    printf("Quick Sort Index Comparisons: %d\n", quickIndexComparisons);
    printf("Quick Sort Element Comparisons: %d\n\n", quickElementComparisons);

    writeToFile(Honeypots, size, "/home/punith/usr-local/02-sem/dsa-c/lab/06lab/quick_sort_output.txt");

    return 0;
}
