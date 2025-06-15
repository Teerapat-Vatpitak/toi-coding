#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, K;
    if (scanf("%d %d", &N, &K) != 2)
        return 0;
    int *C = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &C[i]);
    int *freq = calloc(100001, sizeof(int));
    int distinct = 0, r = 0;
    long long ans = 0;
    for (int l = 0; l < N; l++)
    {
        while (r < N && distinct < K)
        {
            if (freq[C[r]]++ == 0)
                distinct++;
            r++;
        }
        if (distinct < K)
            break;
        ans += (long long)(N - r + 1);
        if (--freq[C[l]] == 0)
            distinct--;
    }
    printf("%lld\n", ans);
    return 0;
}
