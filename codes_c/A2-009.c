#include <stdio.h>

int main()
{
    int N, C;
    if (scanf("%d %d", &N, &C) != 2)
        return 0;
    int a[33][33];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &a[i][j]);
    int w[32], nw[32];
    for (int i = 0; i < N; i++)
        w[i] = i + 1;
    int sz = N, used = 0;
    while (sz > 1)
    {
        int m = 0;
        for (int i = 0; i < sz; i += 2)
        {
            int t1 = w[i], t2 = w[i + 1];
            int winner = a[t1][t2];
            if (!used)
            {
                if (t1 == C && winner != C)
                {
                    winner = C;
                    used = 1;
                }
                else if (t2 == C && winner != C)
                {
                    winner = C;
                    used = 1;
                }
            }
            nw[m++] = winner;
        }
        sz = m;
        for (int i = 0; i < sz; i++)
            w[i] = nw[i];
    }
    printf("%d\n", w[0]);
    return 0;
}
