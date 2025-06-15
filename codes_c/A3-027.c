#include <stdio.h>

int main(void)
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;

    char g[305][305], nxt[305][305];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %c", &g[i][j]);

    /* copy current state to next hour */
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            nxt[i][j] = g[i][j];

    /* water flows only downward one cell */
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i - 1][j] == '*')
                nxt[i][j] = '*';

    /* output */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            putchar(nxt[i][j]);
            if (j + 1 < m)
                putchar(' ');
        }
        if (i + 1 < n)
            putchar('\n');
    }
    return 0;
}
