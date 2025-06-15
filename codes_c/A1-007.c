#include <stdio.h>
int main()
{
    char c;
    scanf(" %c", &c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}
