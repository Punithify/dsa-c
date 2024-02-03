// C program for Naive Pattern Searching algorithm
#include <stdio.h>
#include <string.h>

void nfind(char *string, char *pat)
{
    int i, j = -1, start = 0;
    int lasts = strlen(string) - 1;
    int lastp = strlen(pat) - 1;
    int endmatch = lastp;
    for (i = 0; endmatch <= lasts; endmatch++, start++)
    {
        if (string[endmatch] == pat[lastp])
            for (j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++)
                ;
        if (j == lastp)
        {
            printf("PATTERN is found at position %d \n", start);
            j = 0;
        }
    }
    if (j == -1)
        printf("PATTERN not found\n");
}

int main()
{

    /*
      // CASE---1----PATTERN FOUND
    char txt[] = "ABCABA";
    char pat[] = "CAB";
    */

    // CASE---2----PATTERN NOT FOUND---when first character of pattern is not matching in text
    char txt[] = "ABCABA";
    char pat[] = "ABX";

    /*
     // CASE---3----UNIQUE CHARACTERS IN TEXT AND PATTERN
    char txt[] = "ABCDEFGH";
    char pat[] = "DEF";
    */

    /*
     // CASE---4----PATTERN FOUND IN THE END OF THE TEXT
    char txt[] = "ABCDABCABCDF";
    char pat[] = "ABCDF";
    */

    /*
    // CASE 5----pattern found at multiple places in text
        char txt[] = "AABAACAADAABAAABAA";
        char pat[] = "AABA";
    */

    /*
    // CASE---6---All characters in TEXT & PATTERN ARE SAME
    char txt[] = "AAAAAAAAAAAAAAAAAA";
    char pat[] = "AAAAA";
      */

    /*
    //CASE---7
    char txt[] = "AAAAAB";
    char pat[] = "AAAAB";
      */

    printf("GIVEN TEXT IS %s\n", txt);
    printf("GIVEN PATTERN IS %s\n", pat);

    nfind(txt, pat);
    return 0;
}