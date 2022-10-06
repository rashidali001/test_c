#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct dog
{
    char* name;
    float age;
    char* owner;
};

void print_dog(struct dog *d)
{
    if (d == NULL)
        exit(1);

    if ((d->name == NULL) || (d->name == ""))
        d->name = "(nil)";
    if ((d->owner == NULL) || (d->owner == ""))
        d->owner = "(nil)";
    if (d->age == 0)
        d->age = 0;
    printf("Name: %s\n", d->name);
    printf("Age: %f\n", d->age);
    printf("Owner: %s\n", d->owner);
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    struct dog my_dog;

    my_dog.name = "";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    print_dog(&my_dog);
    return (0);
}
