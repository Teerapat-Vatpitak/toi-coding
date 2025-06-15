#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int e = 0, o = 0;
    if (a % 2 == 0)
        e++;
    else
        o++;
    if (b % 2 == 0)
        e++;
    else
        o++;
    if (c % 2 == 0)
        e++;
    else
        o++;
    printf("even %d\nodd %d\n", e, o);
    return 0;
}
