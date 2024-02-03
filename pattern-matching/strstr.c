#include <stdio.h>
#include <string.h>
int main()
{

    // char string[100] = "This is a test string";
    // char *p;
    // p = strstr(string, "xyz"); // intro to pattern matching

    // CASE---1---BEST CASE
    // char string[100] = "AABCCAADDEE";
    // char *p = "FAA"; // declaration + initialization
    // p = strstr(string, p);

    // CASE---2-----Fails DRAWBACK OF STRSTR

    char string[100] = "AAAAAAAAAAAAAAAAAA";
    char *p = "AAAAA";
    p = strstr(string, p);

    // CASE---3-----WORST CASE DATA FOR STRSTR
    // char string[100] = "AAAAAB";
    // char *p = "AAAAB";
    // p = strstr(string, p);

    if (p)
    {
        printf("string found\n");
        printf("string is found at position %d \n", p - string);
    }
    else
        printf("string not found\n");

    return 0;
}
