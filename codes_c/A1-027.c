#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char s[6];
    scanf("%5s", s);
    for (int i = strlen(s) - 1; i >= 0; i--)
        putchar(tolower(s[i]));
    putchar('\n');
    return 0;
}
