#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int N;
    if (scanf("%d", &N) != 1)
        return 0;
    int *P = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &P[i]);
    }
    int *prefix = malloc((N + 1) * sizeof(int));
    prefix[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        prefix[i] = prefix[i - 1] + P[i - 1];
    }
    int maxSum = prefix[N];
    bool *seen = calloc(maxSum + 1, sizeof(bool));
    int distinct = 0;
    for (int a = 1; a <= N; a++)
    {
        for (int b = a; b <= N; b++)
        {
            int s = prefix[b] - prefix[a - 1];
            if (!seen[s])
            {
                seen[s] = true;
                distinct++;
            }
        }
    }
    printf("%d\n", distinct);
    free(P);
    free(prefix);
    free(seen);
    return 0;
}
