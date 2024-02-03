#include <stdio.h>

void swapVal(int *firstVal,int *SecondVal){
    int temp;
    temp=*firstVal;
    *firstVal=*SecondVal;
    *SecondVal=temp;
}