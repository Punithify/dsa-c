// structure array
#include <stdio.h>

struct date
{
    int d, m, y;
};

struct date inputDate();
void showDate(struct date);

int main()
{

    // struct date d1;
    struct date dob[4]; // space occcuiped 48bytes
    printf("enter four DOB of four students\n");
    int i = 0;
    for (i = 0; i <= 3; i++)
    {
        dob[i] = inputDate();
    }
    // d1=inputDate();
    for (i = 0; i <= 3; i++)
    {
        showDate(dob[i]);
    }
    // d2=d1;//assigning structure d1 to structure d2
    return 0;
}

void showDate(struct date anyDate)
{
    printf("%d-%d-%d\n", anyDate.d, anyDate.m, anyDate.y);
}

struct date inputDate()
{
    struct date anyDate;
    printf("\nEnter a date");
    scanf("%d/%d/%d", &anyDate.d, &anyDate.m, &anyDate.y);
    return anyDate;
}