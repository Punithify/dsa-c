#include <stdio.h>
#include "example.h"
int main()
{
    int n, i;
    struct student stud[3];
    printf("enter number of students \n");
    scanf("%d", &n);        // size
    for (i = 0; i < n; i++) // read and calculate
    {
        printf("enter name\n");
        scanf("%s", &stud[i].name);
        printf("enter roll number\n");
        scanf("%d", &stud[i].rno);
        printf("enter subject 1 marks");
        scanf("%d", &stud[i].marks[0]);
        printf("enter subject 2 marks");
        scanf("%d", &stud[i].marks[1]);
        printf("enter subject 3 marks");
        scanf("%d", &stud[i].marks[2]);
        stud[i].tot = stud[i].marks[0] + stud[i].marks[1] + stud[i].marks[2];
        stud[i].average = stud[i].tot / 3.0;
    }
    display(stud, n);
    return 0;
}

void display(struct student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", s[i].name);
    }
}