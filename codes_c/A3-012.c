#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, S;
    if (scanf("%d %d", &N, &S) != 2)
        return 0;
    int *f = malloc((N + 1) * sizeof(int));
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &f[i]);
    }
    int *vis = calloc(N + 1, sizeof(int));
    int count = 0;
    int cur = S;
    while (cur != 0 && !vis[cur])
    {
        vis[cur] = 1;
        count++;
        cur = f[cur];
    }
    printf("%d\n", count);
    return 0;
}
