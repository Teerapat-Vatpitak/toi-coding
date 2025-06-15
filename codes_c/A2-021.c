#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 305
#define MAXE (MAXN * MAXN + 5)
#define INF 1000000000

int N, K;
int tA1[MAXN], tA2[MAXN], tB1[MAXN], tB2[MAXN];
int head1[MAXN], to1[MAXE], nxt1[MAXE], ec1;
int head2[MAXN], to2[MAXE], nxt2[MAXE], ec2;
int pairU[MAXN], pairV[MAXN], dist[MAXN];
int q[MAXN];

void add_edge1(int u, int v)
{
    to1[++ec1] = v;
    nxt1[ec1] = head1[u];
    head1[u] = ec1;
}

void add_edge2(int u, int v)
{
    to2[++ec2] = v;
    nxt2[ec2] = head2[u];
    head2[u] = ec2;
}

int bfs(int head[], int to[], int nxt[])
{
    int front = 0, back = 0;
    for (int u = 1; u <= N; u++)
    {
        if (pairU[u] == 0)
        {
            dist[u] = 0;
            q[back++] = u;
        }
        else
        {
            dist[u] = INF;
        }
    }
    int found = 0;
    while (front < back)
    {
        int u = q[front++];
        for (int e = head[u]; e; e = nxt[e])
        {
            int v = to[e];
            if (pairV[v] == 0)
            {
                found = 1;
            }
            else if (dist[pairV[v]] == INF)
            {
                dist[pairV[v]] = dist[u] + 1;
                q[back++] = pairV[v];
            }
        }
    }
    return found;
}

int dfs(int u, int head[], int to[], int nxt[])
{
    for (int e = head[u]; e; e = nxt[e])
    {
        int v = to[e];
        if (pairV[v] == 0 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v], head, to, nxt)))
        {
            pairU[u] = v;
            pairV[v] = u;
            return 1;
        }
    }
    dist[u] = INF;
    return 0;
}

int hopcroft_karp(int head[], int to[], int nxt[])
{
    memset(pairU, 0, sizeof(pairU));
    memset(pairV, 0, sizeof(pairV));
    int result = 0;
    while (bfs(head, to, nxt))
    {
        for (int u = 1; u <= N; u++)
        {
            if (pairU[u] == 0)
            {
                result += dfs(u, head, to, nxt);
            }
        }
    }
    return result;
}

int feasible(int T)
{
    // build graph for center1
    ec1 = 0;
    memset(head1, 0, sizeof(head1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (tA1[i] + tB1[j] <= T)
            {
                add_edge1(i, j);
            }
        }
    }
    // build graph for center2
    ec2 = 0;
    memset(head2, 0, sizeof(head2));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (tA2[i] + tB2[j] <= T)
            {
                add_edge2(i, j);
            }
        }
    }
    int m1 = hopcroft_karp(head1, to1, nxt1);
    int m2 = hopcroft_karp(head2, to2, nxt2);
    return (m1 + m2) >= K;
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", &tA1[i]);
    for (int i = 1; i <= N; i++)
        scanf("%d", &tA2[i]);
    for (int j = 1; j <= N; j++)
        scanf("%d", &tB1[j]);
    for (int j = 1; j <= N; j++)
        scanf("%d", &tB2[j]);

    int low = 0, high = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (tA1[i] + tB1[j] > high)
                high = tA1[i] + tB1[j];
            if (tA2[i] + tB2[j] > high)
                high = tA2[i] + tB2[j];
        }
    }

    int ans = high;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (feasible(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}
