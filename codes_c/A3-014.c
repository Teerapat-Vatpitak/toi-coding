#include <stdio.h>

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    int cntL = 0;
    for (int i = 0; i < N; i++)
    {
        int h;
        scanf("%d", &h);
        if (h > 18)
            cntL++;
    }
    int cntS = N - cntL;
    int rest = (cntL > 0 ? cntL - 1 : 0) - cntS;
    if (rest < 0)
        rest = 0;
    printf("%d\n", N + rest);
    return 0;
}
