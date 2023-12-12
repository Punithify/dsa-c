// structure pointer
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
    struct date d1; // space occcuiped 48bytes
    struct date *p;
    printf("enter four DOB of four students\n");
    p = &d1; // passing the structure reference to the pointer variable of type date
    // *p≈d1 important
    *p = inputDate();
    // printf("%d\n", p->d); accessing structure variables using pointers
    showDate(*p);
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