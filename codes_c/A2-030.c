#include <stdio.h>

int main()
{
    int a[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int r = -1, c = -1;
    for (int i = 0; i < 5; i++)
    {
        int s = 0;
        for (int j = 0; j < 5; j++)
            s += a[i][j];
        if (s % 2)
        {
            r = i;
            break;
        }
    }
    for (int j = 0; j < 5; j++)
    {
        int s = 0;
        for (int i = 0; i < 5; i++)
            s += a[i][j];
        if (s % 2)
        {
            c = j;
            break;
        }
    }
    if (r < 0 && c < 0)
        printf("-1 -1\n");
    else
        printf("%d %d\n", r, c);
    return 0;
}
