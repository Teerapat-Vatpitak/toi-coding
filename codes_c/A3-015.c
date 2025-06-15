#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    int *h = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &h[i]);
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (h[i] > h[j])
            {
                int t = h[i];
                h[i] = h[j];
                h[j] = t;
            }
    long long sum = 0, pref = 0;
    for (int i = 0; i < N; i++)
    {
        pref += h[i];
        sum += pref;
    }
    printf("%lld\n", 2 * sum);
    free(h);
    return 0;
}
