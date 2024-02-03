#include <stdio.h>
#include <string.h>

int main()
{
    char src[40];
    char dest[12];

    strcpy(src, "This is my test program");
    strncpy(dest, src, 10);

    printf("Final copied string : %s\n", dest);

    return (0);
}
