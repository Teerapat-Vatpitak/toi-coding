#include <stdio.h>
#define MAXN 200000

int V[MAXN];

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    for (int i = 0; i < N; i++)
    {
        int P;
        scanf("%d %d", &P, &V[i]);
    }
    int maxV = 0, cnt = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (V[i] < maxV)
            cnt++;
        else
            maxV = V[i];
    }
    printf("%d\n", cnt);
    return 0;
}
