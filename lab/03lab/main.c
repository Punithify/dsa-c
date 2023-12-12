#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;
void push(int value);
int pop();
int isOperator(char ch);
int precedence(char ch);
void infixToPostfix(char infix[]);
int evaluatePostfix(char postfix[]);

int main()
{
    char infix[MAX_SIZE];

    printf("Expression for routing an IP :");
    scanf("%s", infix);

    infixToPostfix(infix);

    int result = evaluatePostfix(infix);
    printf("Result: %d\n", result);

    return 0;
}

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0; // For '('
}

void infixToPostfix(char infix[])
{
    char postfix[MAX_SIZE];
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else if (isOperator(infix[i]))
        {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int evaluatePostfix(char postfix[])
{
    int i, operand1, operand2;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else if (isOperator(postfix[i]))
        {
            operand2 = pop();
            operand1 = pop();

            switch (postfix[i])
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            }
        }
    }

    return pop();
}
