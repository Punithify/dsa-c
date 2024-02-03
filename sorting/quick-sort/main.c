#include <stdio.h>

void quickSort(int *a, int first, int last)
{
    int pivot, i, j, temp;
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
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;
        quickSort(a, first, j - 1);
        quickSort(a, j + 1, last);
    }
}

int main()
{
    int a[3] = {12, 44, 23};
    quickSort(a, 0, 2);
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}