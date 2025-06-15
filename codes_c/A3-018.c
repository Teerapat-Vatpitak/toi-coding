#include <stdio.h>

int main()
{
    int L;
    long long N;
    if (scanf("%d %lld", &L, &N) != 2)
        return 0;
    int removed = 0;
    for (int r = 1; r <= L; r++)
    {
        long long layer = (long long)r * r;
        if (N >= layer)
        {
            N -= layer;
            removed++;
        }
        else
        {
            break;
        }
    }
    printf("%d\n", L - removed);
    return 0;
}
