#include <stdio.h>

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    int cnt[301] = {0}, mx = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        if (++cnt[x] > mx)
            mx = cnt[x];
    }
    printf("%d\n", mx);
    return 0;
}
