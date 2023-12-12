#include <stdio.h>

int main()
{

    int a[100], n;
    printf("Enter size of the array : \t");
    scanf("%d", &n);
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    // Operations on 1D array
    // 1. Traversal
    // 2. Insertion (begin,end,b/w)
    printf("Insertion at begining\n");
    for (int i = n - 1; i <= 0; i--)
    {
        a[i + 1] = a[i];
    }
    a[0] = 100;
    printf("After insertion\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}