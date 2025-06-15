#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long s, t;
} I;
int cmp(const void *a, const void *b)
{
    long long x = ((I *)a)->t, y = ((I *)b)->t;
    return (x < y) ? -1 : (x > y);
}

int main()
{
    int N;
    long long L;
    if (scanf("%d %lld", &N, &L) != 2)
        return 0;
    I *a = malloc(N * sizeof(I));
    for (int i = 0; i < N; i++)
        scanf("%lld %lld", &a[i].s, &a[i].t);
    qsort(a, N, sizeof(I), cmp);
    int cnt = 0;
    long long pos = -1;
    for (int i = 0; i < N; i++)
    {
        if (pos < a[i].s)
        {
            pos = a[i].t;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
