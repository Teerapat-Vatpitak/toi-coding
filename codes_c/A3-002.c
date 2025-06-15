#include <stdio.h>
#include <math.h>

int main()
{
    unsigned long n, k, i = 1, o;
    scanf("%d", &n);
    while (n > k)
    {
        k = pow(i, 2);
        i++;
    }
    o = (k - n) % 2;
    if (o == 0)
    {
        printf("%ld", (i - 2) * 2);
    }
    else if (o == 1)
    {
        printf("%ld", ((i - 2) * 2) - 1);
    }
    return 0;
}
