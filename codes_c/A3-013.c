#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    long long S;
    if (scanf("%d %lld", &N, &S) != 2)
        return 0;
    long long minSum = 0, maxSum = 0;
    for (int i = 0; i < N; i++)
    {
        int h;
        scanf("%d", &h);
        long long d1 = 0, d2 = 0;
        if (h % 3 == 0)
            d1 = (long long)(h / 3) * 10;
        if (h % 4 == 0)
            d2 = (long long)(h / 4) * 10;
        long long dmin = d1 && d2 ? (d1 < d2 ? d1 : d2) : (d1 ? d1 : d2);
        long long dmax = d1 && d2 ? (d1 > d2 ? d1 : d2) : (d1 ? d1 : d2);
        minSum += dmin;
        maxSum += dmax;
    }
    long long flatMin = S - maxSum;
    long long flatMax = S - minSum;
    printf("%lld %lld\n", flatMin, flatMax);
    return 0;
}
