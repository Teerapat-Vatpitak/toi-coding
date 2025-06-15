#include <stdio.h>
int main()
{
    int m, e, sum;
    scanf("%d", &m);
    scanf("%d", &e);
    sum = m + e;
    printf("%d\n", sum);
    if (sum >= 50)
        printf("pass\n");
    else
        printf("fail\n");
    return 0;
}
