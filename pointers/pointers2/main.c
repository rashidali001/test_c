#include <stdio.h>
#include <stdlib.h>
#define size 4

float add (float a, float b){return a+b;}
float sub (float a, float b){return a-b;}
float mul (float a, float b){return a*b;}
float divi (float a, float b){return a/b;}

int main()
{
    int choice;
    float a, b;
    float (*ptr_calc[size])(float, float) = {add, sub, mul, divi};
    printf("*****************  Simple Calculator  ***************\n");
    printf("OPERATIONS:\n");
    printf(" 0 - addition\n 1 - subraction \n 2 - multiplication \n 3 - division\n");
    printf("Enter operation:\n");
    scanf("%d", &choice);
    printf("Enter your 2 numbers:\n");
    scanf("%f %f", &a, &b);
    printf("Your result is:\n");
    printf("%f\n\n", ptr_calc[choice](a, b));
    printf("Close calculator by pressing on any key\n");
    return 0;
}
