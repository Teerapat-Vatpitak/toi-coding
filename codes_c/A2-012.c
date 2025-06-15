#include <stdio.h>

int main()
{
    int c, k, t;
    if (scanf("%d %d %d", &c, &k, &t) != 3)
        return 0;
    printf("%d\n", c * 10 + k * 25 + t * 3);
    return 0;
}
