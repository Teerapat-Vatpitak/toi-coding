#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x, d;
} E;

int cmp(const void *a, const void *b)
{
    E *p = (E *)a, *q = (E *)b;
    if (p->x < q->x)
        return -1;
    if (p->x > q->x)
        return 1;
    return p->d - q->d;
}

int main()
{
    int L, N;
    if (scanf("%d %d", &L, &N) != 2)
        return 0;
    E ev[400];
    int m = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        ev[m++] = (E){a, 1};
        ev[m++] = (E){b, -1};
    }
    qsort(ev, m, sizeof(E), cmp);
    int curr = 0, ans = 0;
    for (int i = 0; i < m; i++)
    {
        curr += ev[i].d;
        if (i + 1 == m || ev[i].x != ev[i + 1].x)
        {
            if (curr > ans)
                ans = curr;
        }
    }
    printf("%d\n", ans);
    return 0;
}
