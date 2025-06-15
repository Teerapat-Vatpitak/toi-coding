#include <stdio.h>

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    int route1[305], route2[305];
    for (int i = 1; i <= N; i++)
        scanf("%d", &route1[i]);
    for (int i = 1; i <= N; i++)
        scanf("%d", &route2[i]);
    int prev1 = 1, prev2 = 1, meet = 0;
    for (int i = 1; i <= N; i++)
    {
        int u1 = prev1, v1 = route1[i];
        int u2 = prev2, v2 = route2[i];
        prev1 = v1;
        prev2 = v2;
        if ((u1 == u2 && v1 == v2) || (u1 == v2 && v1 == u2))
        {
            meet++;
            continue;
        }
        if (u1 == u2 || u1 == v2 || v1 == u2 || v1 == v2)
            continue;
        int d1 = (v1 - u1 + N) % N;
        int d_u2 = (u2 - u1 + N) % N;
        int d_v2 = (v2 - u1 + N) % N;
        int in_u2 = (d_u2 > 0 && d_u2 < d1);
        int in_v2 = (d_v2 > 0 && d_v2 < d1);
        if (in_u2 ^ in_v2)
            meet++;
    }
    printf("%d\n", meet);
    return 0;
}
