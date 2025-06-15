#include <stdio.h>
#include <string.h>
int main()
{
    char id[100];
    scanf("%s", id);
    if (strlen(id) == 13)
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
