#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = N; i >= 0; i--)
    {
        if (i % 10 == 0)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
