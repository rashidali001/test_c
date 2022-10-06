#include <stdio.h>
#include <stdlib.h>
char *str_concat(char *s1, char *s2)
{
    char *concat_string;
    int length_s1, length_s2;
    int i = 0, j = 0;


    for(length_s1 = 0; s1[length_s1] != '\0'; length_s1++)
        ;

    for(length_s2 = 0; s2[length_s2] != '\0'; length_s2++)
        ;

    concat_string = (char *)malloc(sizeof(char) * (length_s1 + length_s2 + 1));

    while (s1[i] != '\0')
    {
        concat_string[i] = s1[i];
        i++;
    }

    while (s2[j] != '\0')
    {
        concat_string[i] = s2[j];
        i++;
        j++;
    }

    concat_string[i++] = '\0';

    return concat_string;




    printf("%d", length_s1);

}
/**
 * main - check the code for ALX School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s;

    s = str_concat("Betty ", "Holberton");
    if (s == NULL)
    {
        printf("failed\n");
        return (1);
    }
    printf("%s\n", s);
    free(s);
    return (0);
}
