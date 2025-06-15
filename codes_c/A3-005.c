#include <stdio.h>
#include <stdlib.h>

int cmpInt(const void *a, const void *b)
{
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return (ia > ib) - (ia < ib);
}

int main()
{
    int N, M;
    if (scanf("%d %d", &N, &M) != 2)
        return 0;
    if (M <= 0)
    {
        printf("0\n");
        return 0;
    }
    int *starts = malloc(M * sizeof(int));
    int *ends = malloc(M * sizeof(int));
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &starts[i], &ends[i]);
    }

    qsort(starts, M, sizeof(int), cmpInt);
    qsort(ends, M, sizeof(int), cmpInt);
    int i = 0, j = 0;
    int count = 0, maxcount = 0;

    while (i < M && j < M)
    {
        if (starts[i] <= ends[j])
        {
            count++;
            if (count > maxcount)
                maxcount = count;
            i++;
        }
        else
        {
            count--;
            j++;
        }
    }
    printf("%d\n", maxcount);
    free(starts);
    free(ends);
    return 0;
}
