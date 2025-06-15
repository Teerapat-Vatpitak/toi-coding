#include <stdio.h>
int main()
{
    int age;
    char s;
    scanf("%d", &age);
    scanf(" %c", &s);
    if (age < 18 || s == 's' || s == 'S')
        printf("20\n");
    else
        printf("50\n");
    return 0;
}
