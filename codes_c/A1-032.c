#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        putchar('*');
    putchar('\n');
    int k = n - 2;
    if (k >= 1)
    {
        for (int i = 0; i < k; i++)
            putchar('*');
    }
    putchar('\n');
    int m = n - 4;
    if (m >= 1)
    {
        for (int i = 0; i < m; i++)
            putchar('*');
    }
    putchar('\n');
    return 0;
}
