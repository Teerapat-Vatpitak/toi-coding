#include <stdio.h>

int main()
{
    int N, M;
    if (scanf("%d %d", &N, &M) != 2)
        return 0;
    char a[305][305], b[305][305];
    for (int i = 0; i < N; i++)
        scanf("%s", a[i]);
    for (int i = 0; i < N; i++)
        scanf("%s", b[i]);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char x = a[i][j], y = b[i][j], z;
            if (x == '-' && y == '-')
                z = '-';
            else if (x == '-' && y == 'x')
                z = 'x';
            else if (x == '+' && y == '-')
                z = '+';
            else /* x=='+' && y=='x' */
                z = '*';
            putchar(z);
        }
        if (i < N - 1)
            putchar('\n');
    }
    return 0;
}
