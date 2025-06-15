#include <stdio.h>
#include <string.h>
int main()
{
    char name[100], surname[100], alias[5];
    scanf("%s", name);
    scanf("%s", surname);
    printf("Hello %s %s\n", name, surname);
    alias[0] = name[0];
    alias[1] = name[1];
    alias[2] = surname[0];
    alias[3] = surname[1];
    alias[4] = '\0';
    printf("%s\n", alias);
    return 0;
}
