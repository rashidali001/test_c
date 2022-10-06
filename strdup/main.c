#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *_strduup(char *str)
{
    char *str_cpy;
    int length;
    for(length = 0; str[length] != '\0'; length++)
        ;
    str_cpy = (char *)malloc(sizeof(char) * length + 1);
    for (int i = 0; i < (sizeof(str) / sizeof(str[0])) ; i++)
    {
        str_cpy[i] = str[i];
    }
    str_cpy[length + 1] = '\0';

    return str_cpy;
    free(str_cpy);

}

/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s;

    s = _strduup("ALX SE");
    if (s == NULL)
    {
        printf("failed to allocate memory\n");
        return (1);
    }
    printf("%s\n", s);
    free(s);
    return (0);
}
