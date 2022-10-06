#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=10,b=20,*p1=&a,*p2=&b;
    printf("Before Swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;

    printf("After Swapping:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}
