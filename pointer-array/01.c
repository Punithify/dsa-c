#include <stdio.h>

void input(int *p);
void display(int *p);

int main()
{
    int a[5];
    // p = &a[0]; // pointer p contains the address of the first block of array a.
    input(a);
    display(a);
    return 0;
}

void input(int *p)
{
    printf("Enter array elements :\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", p + i);
    }
}

void display(int *p)
{
    printf("The array elements are :\n");
    for (int i = 0; i <= 4; i++)
    {
        printf("%d\n", *(p + i));
    }
}