#include <stdio.h>
#include <stdlib.h>
struct Profile
{
    char *name;
    char *email;
    int age;
};

struct Profile *new_user(char *name, char *email, int age)
{
    struct Profile *user;
    user = malloc(sizeof(struct Profile));
    if (user == NULL)
        return NULL;
    user->name = name;
    user->email = email;
    user->age = 22;

    return user;
    free(user);
}

int main()
{
    struct Profile *user;

    user = new_user("Rashid", "rashidestonian@gmail.com", 22);
    printf("%s\n", user->name);
    printf("%s\n", user->email);
    printf("%d\n", user->age);
    return 0;
}
