#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        if (i % 5 == 0)
            putchar('X');
        else
            putchar('*');
    }
    putchar('\n');
    return 0;
}
