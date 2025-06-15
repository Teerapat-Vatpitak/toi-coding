#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int A, B;
    if (scanf("%d %d", &A, &B) != 2)
        return 0;
    int maxP = 3 * B;
    char *isPrime = malloc(maxP + 1);
    for (int i = 0; i <= maxP; i++)
        isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    int lim = (int)sqrt(maxP);
    for (int i = 2; i <= lim; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxP; j += i)
                isPrime[j] = 0;
        }
    }
    int *pi = malloc((maxP + 1) * sizeof(int));
    pi[0] = 0;
    for (int i = 1; i <= maxP; i++)
    {
        pi[i] = pi[i - 1] + isPrime[i];
    }
    long long ans = 0;
    for (int a = A; a <= B; a++)
    {
        for (int b = a; b <= B; b++)
        {
            int lo = a + 2 * b;
            if (lo > maxP)
                continue;
            int hi = a + b + B;
            if (hi > maxP)
                hi = maxP;
            ans += pi[hi] - pi[lo - 1];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
