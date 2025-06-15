#include <stdio.h>

int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < 10; i++)
    {
        int dup = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] == a[i])
            {
                dup = 1;
                break;
            }
        }
        if (!dup)
        {
            if (i > 0)
                printf(" ");
            printf("%d", a[i]);
        }
    }
    return 0;
}
