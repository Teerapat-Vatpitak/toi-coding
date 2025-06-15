#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int x, m;
    scanf("%d", &m);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &x);
        if (x < m)
            m = x;
    }
    printf("%d\n", m);
    return 0;
}
