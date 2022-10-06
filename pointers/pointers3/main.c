#include <stdio.h>
#include <stdlib.h>

float add(int a, int b){return a+b;}

int main()
{
    int num1 = 7, num2 = 3;
    float (*ptr_add)(int, int) = add;
    printf("%f\n", ptr_add(num1, num2));
    return 0;
}
