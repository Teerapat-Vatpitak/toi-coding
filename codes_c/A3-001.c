#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    int *A = malloc((N + 1) * sizeof(int));
    int *L = malloc((N + 1) * sizeof(int));
    int *B = malloc((N + 1) * sizeof(int));
    int *R = malloc((N + 1) * sizeof(int));
    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d %d %d", &A[i], &L[i], &B[i], &R[i]);
    }
    long long *W = malloc((N + 1) * sizeof(long long));
    long long *add = malloc((N + 1) * sizeof(long long));
    for (int i = N; i >= 1; i--)
    {
        long long WL = A[i] ? L[i] : W[L[i]];
        long long addL = A[i] ? 0 : add[L[i]];
        long long WR = B[i] ? R[i] : W[R[i]];
        long long addR = B[i] ? 0 : add[R[i]];
        long long D = WL > WR ? WL - WR : WR - WL;
        add[i] = addL + addR + D;
        W[i] = WL + WR + D;
    }
    printf("%lld\n", add[1]);
    return 0;
}
