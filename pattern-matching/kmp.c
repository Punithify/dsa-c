#include <stdio.h>
#include <string.h>

char pat[4] = "AAABB";
char failure[5];

void preprocess()
{
    int n = strlen(pat);
    int i;
    failure[0] = -1;
    for (int j = 1; j < n; j++)
    {
        i = failure[j - 1];
        while (pat[j] != pat[i + 1] && i >= 0)
        {
            i = failure[j];
        }
        if (pat[j] == pat[i + 1])
        {
            failure[j] = i + 1;
        }
        else
        {
            failure[j] = -1;
        }
    }
}

int main()
{
    preprocess();
    for (int i = 0; i < 5; i++)
    {
        printf("%c", failure[i]);
    }
    return 0;
}