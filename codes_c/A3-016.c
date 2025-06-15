#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    if (scanf("%d %d", &N, &M) != 2)
        return 0;
    int *need = malloc((M + 1) * sizeof(int));
    int *out = malloc((M + 1) * sizeof(int));
    int *cnt = malloc((M + 1) * sizeof(int));
    int *next = malloc((M + 1) * sizeof(int));
    int *head = malloc((N + 2) * sizeof(int));
    int *to = malloc((200000 + 5) * sizeof(int));
    int *nxt = malloc((200000 + 5) * sizeof(int));
    for (int i = 1; i <= N; i++)
        head[i] = -1;
    int ec = 0;
    for (int i = 1; i <= M; i++)
    {
        int K;
        scanf("%d", &K);
        need[i] = K;
        for (int j = 0; j < K; j++)
        {
            int s;
            scanf("%d", &s);
            nxt[ec] = head[s];
            to[ec] = i;
            head[s] = ec++;
        }
        scanf("%d", &out[i]);
    }
    int *on = calloc(N + 1, sizeof(int));
    int *q = malloc((N + 1) * sizeof(int));
    int qb = 0, qe = 0;
    on[1] = 1;
    q[qe++] = 1;
    while (qb < qe)
    {
        int u = q[qb++];
        for (int e = head[u]; e != -1; e = nxt[e])
        {
            int i = to[e];
            if (--need[i] == 0 && !on[out[i]])
            {
                on[out[i]] = 1;
                q[qe++] = out[i];
            }
        }
    }
    int cntOn = 0;
    for (int i = 1; i <= N; i++)
        if (on[i])
            cntOn++;
    printf("%d\n", cntOn);
    return 0;
}
