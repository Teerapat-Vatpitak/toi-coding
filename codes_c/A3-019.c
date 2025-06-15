#include <stdio.h>

int H[100002], idx[105];

int main()
{
    int N, L;
    if (scanf("%d %d", &N, &L) != 2)
        return 0;
    for (int i = 1; i <= N; i++)
        scanf("%d", &H[i]);
    for (int j = 0; j < L; j++)
        scanf("%d", &idx[j]);
    int prefMax = 0, p = 0;
    for (int i = 1; i <= N; i++)
    {
        if (prefMax < H[i])
            prefMax = H[i];
        while (p < L && idx[p] == i)
        {
            int need = prefMax > H[i] ? prefMax - H[i] + 1 : 0;
            printf("%d\n", need);
            p++;
        }
    }
    return 0;
}
