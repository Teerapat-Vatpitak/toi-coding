#include <stdio.h>

int main()
{
    int N, K;
    if (scanf("%d %d", &N, &K) != 2)
        return 0;
    long long sfast = 1e18;
    int fastIdx = -1;
    static long long S[100001];
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &S[i]);
        if (S[i] < sfast)
        {
            sfast = S[i];
            fastIdx = i;
        }
    }
    int survive = 0;
    long long limit = (long long)K * sfast;
    for (int i = 1; i <= N; i++)
    {
        long long laps = limit / S[i];
        if (laps >= K - 1)
            survive++;
    }
    printf("%d\n", survive);
    return 0;
}
