#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, k;
    if (scanf("%d %d", &n, &m) != 2)
        return 0;
    if (scanf("%d", &k) != 1)
        return 0;
    int rows = n + 2, cols = m + 2;
    int *grid = calloc(rows * cols, sizeof(int));
    for (int i = 0, x, y; i < k; i++)
    {
        scanf("%d %d", &x, &y);
        grid[(x + 1) * cols + (y + 1)]++;
    }
    int best = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i * cols + j] == 0)
            {
                int sum = 0;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        sum += grid[(i + di) * cols + (j + dj)];
                    }
                }
                if (sum > best)
                    best = sum;
            }
        }
    }
    printf("%d\n", best);
    free(grid);
    return 0;
}
