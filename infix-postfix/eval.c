#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stack[100];
int size, top = -1;
int main()
{

    char exp[100];
    char *e;
    int i = 0;
    printf("Enter a expression");
    scanf("%s", exp);
    while (exp[i] != '\0')
    {
        i++;
    }
    exp[i] = ')';
    fflush(stdin);
    printf("%s", exp);
    e = exp;
    while (*e != ')')
    {
        if (isalpha(*e))
        {
            push(*e);
        }
        else
        {
            pop();
        }
    }

    return 0;
}