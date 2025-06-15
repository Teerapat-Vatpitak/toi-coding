#include <stdio.h>
#include <string.h>
int main()
{
    char name[100], surname[100];
    int age;
    scanf("%s%s%d", name, surname, &age);
    int ln = strlen(name), ls = strlen(surname);
    if (ln > 5 && ls > 5)
    {
        printf("%c%c%c%d\n", name[0], name[1], surname[ls - 1], age % 10);
    }
    else
    {
        printf("%c%d%c\n", name[0], age, surname[ls - 1]);
    }
    return 0;
}
