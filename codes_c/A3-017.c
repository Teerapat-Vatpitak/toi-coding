#include <stdio.h>
#include <stdint.h>

int main()
{
    int64_t W, L;
    int M, N;
    if (scanf("%lld %lld %d %d", &W, &L, &M, &N) != 4)
        return 0;
    int64_t area = W * L;
    int64_t best = area;
    for (int A = M; A <= N; A++)
    {
        int64_t perRow = L / A;
        int64_t used1 = perRow * W;
        int64_t remLen = L - perRow * A;
        int64_t perCol = W / A;
        int64_t used2 = remLen * perCol;
        int64_t items = used1 + used2;
        int64_t remArea = area - items * A;
        if (remArea < best)
            best = remArea;
    }
    printf("%lld\n", best);
    return 0;
}
