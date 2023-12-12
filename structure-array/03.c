#include <stdio.h>

// & - address of operator
// * - dereferencing operator/indirection
// pointer will always contain the base address

int main()
{

    int a = 5, *p;
    p = &a;
    printf("%d\n", *p);
    // printf("%d\n", *&a);
    return 0;
}