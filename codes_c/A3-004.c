#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int cmp_int(const void *a, const void *b)
{
    int va = *(const int *)a;
    int vb = *(const int *)b;
    return (va < vb) ? -1 : (va > vb);
}

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    int *U = malloc(N * sizeof(int));
    int *V = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        U[i] = x + y;
        V[i] = x - y;
    }
    qsort(U, N, sizeof(int), cmp_int);
    qsort(V, N, sizeof(int), cmp_int);
    int u_med = U[N / 2];
    int v_med = V[N / 2];
    long long S = 0;
    for (int i = 0; i < N; i++)
    {
        S += llabs((long long)U[i] - u_med);
        S += llabs((long long)V[i] - v_med);
    }
    printf("%lld\n", S);
    return 0;
}
