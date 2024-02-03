#include <stdio.h>
#include <string.h>

int main()
{

    char string[100] = "AAAAAAAAAIIIII";
    char *p = "AAAA";
    // char *res = NULL;
    p = strstr(string, p);
    if (p)
    {
        printf("Pattern found\n");
    }

    return 0;
}