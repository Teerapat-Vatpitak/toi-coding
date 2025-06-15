#include <stdio.h>

int p[100001], visited[100001];

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    for (int i = 1; i <= N; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= N; i++)
        visited[i] = 0;
    int maxlen = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            int cnt = 0, u = i;
            do
            {
                visited[u] = 1;
                u = p[u];
                cnt++;
            } while (u != i);
            if (cnt > maxlen)
                maxlen = cnt;
        }
    }
    printf("%d\n", maxlen);
    return 0;
}
