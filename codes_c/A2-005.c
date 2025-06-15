#include <stdio.h>
#include <stdlib.h>

int cmp_desc(const void *a, const void *b)
{
    int x = *(const int *)a, y = *(const int *)b;
    return (x < y) - (x > y);
}

int main()
{
    int W, H, M, N;
    if (scanf("%d %d %d %d", &W, &H, &M, &N) != 4)
        return 0;
    int *X = malloc((M + 2) * sizeof(int));
    int *Y = malloc((N + 2) * sizeof(int));
    X[0] = 0;
    for (int i = 1; i <= M; i++)
        scanf("%d", &X[i]);
    X[M + 1] = W;
    Y[0] = 0;
    for (int j = 1; j <= N; j++)
        scanf("%d", &Y[j]);
    Y[N + 1] = H;

    int m = M + 1, n = N + 1;
    int *w = malloc(m * sizeof(int));
    int *h = malloc(n * sizeof(int));
    for (int i = 0; i < m; i++)
        w[i] = X[i + 1] - X[i];
    for (int j = 0; j < n; j++)
        h[j] = Y[j + 1] - Y[j];

    free(X);
    free(Y);

    qsort(w, m, sizeof(int), cmp_desc);
    qsort(h, n, sizeof(int), cmp_desc);

    long long best1 = (long long)w[0] * h[0];
    long long cand1 = (long long)w[1] * h[0];
    long long cand2 = (long long)w[0] * h[1];
    long long best2 = cand1 > cand2 ? cand1 : cand2;

    printf("%lld %lld\n", best1, best2);
    return 0;
}
