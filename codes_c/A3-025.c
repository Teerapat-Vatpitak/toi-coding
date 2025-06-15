#include <stdio.h>
#include <string.h>

int cnt[100002], mark[100002];

int main()
{
    int N, W, L;
    if (scanf("%d %d %d", &N, &W, &L) != 3)
        return 0;
    for (int i = 0; i < N; i++)
    {
        int K;
        scanf("%d", &K);
        memset(mark, 0, (W + 2) * sizeof(int));
        for (int j = 0; j < K; j++)
        {
            int h;
            scanf("%d", &h);
            for (int s = -L; s <= L; s++)
            {
                int p = h + s;
                if (p >= 1 && p <= W)
                    mark[p] = 1;
            }
        }
        for (int x = 1; x <= W; x++)
            if (mark[x])
                cnt[x]++;
    }
    for (int x = 1; x <= W; x++)
    {
        if (cnt[x] == N)
        {
            printf("1\n");
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
