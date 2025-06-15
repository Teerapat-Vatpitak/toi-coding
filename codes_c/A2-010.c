#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000

int parent[MAXN + 2];
long long block_size[MAXN + 2];
int active[MAXN + 2];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

typedef struct
{
    int h, i;
} P;
P arr[MAXN];

int cmp(const void *a, const void *b)
{
    const P *p1 = a, *p2 = b;
    return p2->h - p1->h;
}

int main()
{
    int N, Q;
    if (scanf("%d %d", &N, &Q) != 2)
        return 0;
    static int D[MAXN + 2], L[MAXN + 2], H[MAXN + 2];
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &D[i], &L[i]);
    }
    H[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        H[i] = H[i - 1] + D[i];
    }
    for (int i = 1; i <= N; i++)
    {
        arr[i - 1].h = H[i];
        arr[i - 1].i = i;
    }
    qsort(arr, N, sizeof(P), cmp);
    for (int i = 0; i <= N + 1; i++)
    {
        parent[i] = i;
        block_size[i] = 0;
        active[i] = 0;
    }
    long long total_length = 0;
    for (int i = 1; i <= N; i++)
        total_length += L[i];
    static int depths[MAXN], K = 0;
    static long long F[MAXN], global_max = 0;
    for (int idx = 0; idx < N;)
    {
        int d = arr[idx].h;
        int j = idx;
        while (j < N && arr[j].h == d)
        {
            int u = arr[j].i;
            active[u] = 1;
            parent[u] = u;
            block_size[u] = L[u];
            if (active[u - 1])
            {
                int a = find(u), b = find(u - 1);
                if (a != b)
                {
                    parent[b] = a;
                    block_size[a] += block_size[b];
                }
            }
            if (active[u + 1])
            {
                int a = find(u), b = find(u + 1);
                if (a != b)
                {
                    parent[b] = a;
                    block_size[a] += block_size[b];
                }
            }
            long long sz = block_size[find(u)];
            if (sz > global_max)
                global_max = sz;
            j++;
        }
        depths[K] = d;
        F[K] = global_max;
        K++;
        idx = j;
    }
    static long long W[MAXN], ans[MAXN];
    for (int qi = 0; qi < Q; qi++)
    {
        scanf("%lld", &W[qi]);
    }
    for (int qi = 0; qi < Q; qi++)
    {
        long long w = W[qi];
        if (w > total_length)
        {
            ans[qi] = 0;
        }
        else
        {
            int l = 0, r = K - 1, pos = K;
            while (l <= r)
            {
                int m = (l + r) >> 1;
                if (F[m] >= w)
                {
                    pos = m;
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            ans[qi] = depths[pos];
        }
    }
    for (int qi = 0; qi < Q; qi++)
    {
        printf("%lld\n", ans[qi]);
    }
    return 0;
}
