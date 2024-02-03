#include <stdio.h>
#include <string.h>
// last occurence
int main()
{
    char string[55] = "This is a string for testing";
    char *p;
    p = strrchr(string, 'i');

    printf("Character i is found at position %d\n", p - string + 1);

    return 0;
}
