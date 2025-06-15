#include <stdio.h>

int main()
{
    int N, K, T;
    if (scanf("%d %d %d", &N, &K, &T) != 3)
        return 0;

    if (T == 1)
    {
        printf("1\n");
        return 0;
    }

    int current = 1;
    int count = 1;

    while (1)
    {
        int next = current + K;
        if (next > N)
            next -= N;
        if (next == 1)
            break;
        count++;
        if (next == T)
            break;
        current = next;
    }

    printf("%d\n", count);
    return 0;
}
