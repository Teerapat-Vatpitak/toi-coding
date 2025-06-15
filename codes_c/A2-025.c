#include <stdio.h>

int main()
{
    int R, C, sr, sc, N;
    if (scanf("%d %d", &R, &C) != 2)
        return 0;
    scanf("%d %d", &sr, &sc);
    scanf("%d", &N);
    int ri[N], ci[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &ri[i], &ci[i]);
    }
    int safe = 0;
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            int dmin = 1000000;
            for (int i = 0; i < N; i++)
            {
                int dr = r - ri[i];
                if (dr < 0)
                    dr = -dr;
                int dc = c - ci[i];
                if (dc < 0)
                    dc = -dc;
                int d = dr > dc ? dr : dc;
                if (d < dmin)
                    dmin = d;
                if (dmin == 0)
                    break;
            }
            if (dmin > 2)
                safe++;
        }
    }
    int dmin = 1000000;
    for (int i = 0; i < N; i++)
    {
        int dr = sr - ri[i];
        if (dr < 0)
            dr = -dr;
        int dc = sc - ci[i];
        if (dc < 0)
            dc = -dc;
        int d = dr > dc ? dr : dc;
        if (d < dmin)
            dmin = d;
        if (dmin == 0)
            break;
    }
    printf("%d\n", safe);
    if (dmin == 0)
        printf("100%%\n");
    else if (dmin <= 1)
        printf("60%%\n");
    else if (dmin <= 2)
        printf("20%%\n");
    else
        printf("0%%\n");
    return 0;
}
