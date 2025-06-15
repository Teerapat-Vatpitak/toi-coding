#include <stdio.h>
#include <string.h>
int main()
{
    char id[9];
    scanf("%8s", id);
    if (id[2] == '1' && id[3] == '6')
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
