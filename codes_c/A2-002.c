#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long key;
    long long x;
} Node;

int cmp(const void *a, const void *b)
{
    const Node *p = a, *q = b;
    if (p->key < q->key)
        return -1;
    if (p->key > q->key)
        return 1;
    if (p->x < q->x)
        return -1;
    if (p->x > q->x)
        return 1;
    return 0;
}

long long solve(Node *arr, int n)
{
    qsort(arr, n, sizeof(Node), cmp);
    long long best = 0;
    for (int i = 0; i < n;)
    {
        int j = i + 1;
        while (j < n && arr[j].key == arr[i].key)
            j++;
        if (j - i >= 2)
        {
            long long d = arr[j - 1].x - arr[i].x;
            if (d > best)
                best = d;
        }
        i = j;
    }
    return best;
}

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;

    long long *X = malloc(N * sizeof(long long));
    long long *Y = malloc(N * sizeof(long long));
    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld", &X[i], &Y[i]);
    }

    Node *a1 = malloc(N * sizeof(Node));
    Node *a2 = malloc(N * sizeof(Node));
    for (int i = 0; i < N; i++)
    {
        a1[i].key = Y[i] - X[i];
        a1[i].x = X[i];
        a2[i].key = Y[i] + X[i];
        a2[i].x = X[i];
    }

    long long ans1 = solve(a1, N);
    long long ans2 = solve(a2, N);
    long long ans = (ans1 > ans2) ? ans1 : ans2;

    printf("%lld\n", ans);

    free(X);
    free(Y);
    free(a1);
    free(a2);
    return 0;
}
