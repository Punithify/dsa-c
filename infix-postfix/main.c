#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stack[100];
int size, top = -1;

int precedence(char operator) // bodmas rules
{
    if (operator== '(')
        return 0;
    if (operator== '+' || operator== '-')
        return 1;
    if (operator== '*' || operator== '/')
        return 2;
}

void push(char ele)
{
    top++;
    // printf("%c", ele);
    stack[top] = ele;
}

char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int main()
{

    char exp[100];
    char *e, x;
    printf("Enter a expression");
    scanf("%s", exp);
    e = exp;

    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            printf("%c\t", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c\t", x);
            }
        }
        else
        {
            while (precedence(stack[top]) >= precedence(*e))
            {
                printf("%c\t", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c\t", pop());
    }

    return 0;
}