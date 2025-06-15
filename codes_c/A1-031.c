#include <stdio.h>
int main()
{
    int x;
    scanf("%d", &x);
    int t = x / 1000;
    int r = x % 1000;
    printf("%d,%03d\n", t, r);
    return 0;
}
