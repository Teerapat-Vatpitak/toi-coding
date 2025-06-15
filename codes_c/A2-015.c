#include <stdio.h>

int main()
{
    int w, l, n;
    int price;
    if (scanf("%d %d %d", &w, &l, &n) != 3)
        return 0;
    scanf("%d", &price);
    int length = 2 * (w + l) * n;
    int cost = length * price;
    printf("%d\n%d\n", length, cost);
    return 0;
}
