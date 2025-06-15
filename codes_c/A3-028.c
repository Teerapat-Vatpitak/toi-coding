#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;
    int b;
    scanf("%d", &b);
    char **g = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        g[i] = malloc(m);
        for (int j = 0; j < m; j++)
            g[i][j] = 0;
    }
    int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int k = 0; k < b; k++)
    {
        int r, c;
        scanf("%d %d", &r, &c);
        g[r][c] = -1;
        for (int t = 0; t < 8; t++)
        {
            int nr = r + dr[t], nc = c + dc[t];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] != -1)
                g[nr][nc]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == -1)
                printf("x");
            else
                printf("%d", g[i][j]);
            if (j < m - 1)
                printf(" ");
        }
        if (i < n - 1)
            printf("\n");
    }
    return 0;
}
