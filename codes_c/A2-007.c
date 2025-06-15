#include <stdio.h>
#include <stdlib.h>

#define MAXN 305
#define INF 1000000000

int N, M, A[MAXN], B[MAXN], mark[MAXN], parent[MAXN], head[MAXN], nxt[MAXN], sz[MAXN], mc[MAXN], roots[MAXN], rcnt;
struct DP
{
    int sel, rem;
} dp0[MAXN], dp1[MAXN];
int S[MAXN], Sc;

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
struct DP add(struct DP a, struct DP b) { return (struct DP){a.sel + b.sel, a.rem + b.rem}; }
struct DP best(struct DP a, struct DP b) { return a.sel < b.sel || (a.sel == b.sel && a.rem < b.rem) ? a : b; }

void dfs(int u)
{
    sz[u] = 1;
    mc[u] = mark[u];
    for (int v = head[u]; v; v = nxt[v])
    {
        dfs(v);
        sz[u] += sz[v];
        mc[u] += mc[v];
    }
    dp1[u].sel = 1;
    dp1[u].rem = sz[u] - mc[u];
    if (mark[u])
    {
        dp0[u].sel = INF;
        dp0[u].rem = INF;
    }
    else
    {
        dp0[u].sel = 0;
        dp0[u].rem = 0;
        for (int v = head[u]; v; v = nxt[v])
            dp0[u] = add(dp0[u], best(dp0[v], dp1[v]));
    }
}

void recon(int u)
{
    if (mc[u] == 0)
        return;
    struct DP b0 = dp0[u], b1 = dp1[u], b = best(b0, b1);
    if (b.sel == b1.sel && b.rem == b1.rem)
    {
        S[Sc++] = u;
    }
    else
    {
        for (int v = head[u]; v; v = nxt[v])
            recon(v);
    }
}

int main()
{
    if (scanf("%d %d", &N, &M) != 2)
        return 0;
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &A[i], &B[i]);
    for (int i = 1; i <= N; i++)
    {
        mark[i] = 0;
        parent[i] = 0;
        head[i] = 0;
    }
    for (int i = 0, x; i < M; i++)
    {
        scanf("%d", &x);
        mark[x] = 1;
    }
    int st[MAXN], top = 0;
    for (int i = 1; i <= N; i++)
    {
        while (top > 0 && B[st[top - 1]] < B[i])
            top--;
        parent[i] = top ? st[top - 1] : 0;
        st[top++] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        if (parent[i] == 0)
            roots[rcnt++] = i;
        else
        {
            nxt[i] = head[parent[i]];
            head[parent[i]] = i;
        }
    }
    head[0] = 0;
    for (int i = 0; i < rcnt; i++)
    {
        int u = roots[i];
        nxt[u] = head[0];
        head[0] = u;
    }
    mark[0] = 0;
    dfs(0);
    Sc = 0;
    for (int v = head[0]; v; v = nxt[v])
        recon(v);
    qsort(S, Sc, sizeof(int), cmp);
    printf("%d\n", Sc);
    for (int i = 0; i < Sc; i++)
        printf("%d%c", S[i], i + 1 < Sc ? ' ' : '\n');
    if (Sc)
        printf("\n");
    return 0;
}
