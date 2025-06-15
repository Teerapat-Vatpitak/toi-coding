#include <stdio.h>
#include <string.h>
int main()
{
    char c;
    char code[10];
    scanf(" %c", &c);
    scanf("%s", code);
    if (c == 'H' && strcmp(code, "4567") == 0)
        printf("safe unlocked\n");
    else if (c == 'H')
        printf("safe locked - change digit\n");
    else if (strcmp(code, "4567") == 0)
        printf("safe locked - change char\n");
    else
        printf("safe locked\n");
    return 0;
}
