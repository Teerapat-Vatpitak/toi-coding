#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0, a, b;
    int first = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        int m = (a > b ? a : b);
        if (!first)
            printf(" + ");
        printf("%d", m);
        first = 0;
        sum += m;
    }
    printf(" = %d\n", sum);
    return 0;
}
