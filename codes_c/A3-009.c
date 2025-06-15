#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, K;
    if (scanf("%d %d", &N, &K) != 2)
        return 0;
    int *cnt = calloc(K + 1, sizeof(int));
    int ready = 0;
    for (int i = 0; i < N; i++)
    {
        int r;
        scanf("%d", &r);
        if (cnt[r] == 0)
            ready++;
        cnt[r]++;
        if (ready == K)
        {
            for (int j = 1; j <= K; j++)
            {
                cnt[j]--;
                if (cnt[j] == 0)
                    ready--;
            }
        }
    }
    int remain = 0;
    for (int j = 1; j <= K; j++)
        remain += cnt[j];
    printf("%d\n", remain);
    return 0;
}
