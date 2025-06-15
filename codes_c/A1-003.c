#include <stdio.h>
int main()
{
    int a, b, c, m;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    m = a;
    if (b > m)
        m = b;
    if (c > m)
        m = c;
    printf("%d\n", m);
    return 0;
}
