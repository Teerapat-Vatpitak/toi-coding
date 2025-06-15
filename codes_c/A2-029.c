#include <stdio.h>

int main()
{
    int n;
    if (scanf("%d", &n) != 1)
        return 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1 || j == i || i == n)
                printf("0");
            else
                printf("1");
            if (j < i)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
