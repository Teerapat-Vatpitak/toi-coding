#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int d1 = n % 10;
    int d2 = (n / 10) % 10;
    int d3 = (n / 100) % 10;
    int d4 = (n / 1000) % 10;
    printf("%d%d%d%d\n", d1, d2, d3, d4);
    return 0;
}
