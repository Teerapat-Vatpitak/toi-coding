#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long L, N;
    if (scanf("%lld %lld", &L, &N) != 2)
        return 0;
    long long j = 1;
    while (1)
    {
        long long x = L * j;
        if (x * (x + 1) / 2 >= N)
            break;
        j++;
    }
    printf("%lld\n", j);
    return 0;
}
