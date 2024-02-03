#include <stdio.h>
#include <string.h>
// first char pattern match with text
void search(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    /* A loop to slide pat[] one by one */
    for (i = 0; i <= N - M; i++)
    {

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            printf("Pattern found at index %d \n", i);
    }
}

int main()
{
    // CASE 1

    // char txt[] = "AABAACAADAABAAABAA";
    // char pat[] = "AABA";

    // CASE---2---
    // char txt[] = "AABCCAADDEE";
    // char pat[] = "FAA";

    // CASE---3

    char txt[] = "AAAAAAAAAAAAAAAAAA";
    char pat[] = "AAAAA";

    // CASE---4
    // char txt[] = "AAAAAAAAAAAAAAAAAB";
    // char pat[] = "AAAAB";

    search(pat, txt);
    return 0;
}