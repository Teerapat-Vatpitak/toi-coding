#include <stdio.h>
#include <string.h>
int main()
{
    char s[6];
    scanf("%5s", s);
    int count = 1;
    for (int i = 1; i <= 5; i++)
    {
        if (i < 5 && s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            printf("%d%c", count, s[i - 1]);
            count = 1;
        }
    }
    return 0;
}
