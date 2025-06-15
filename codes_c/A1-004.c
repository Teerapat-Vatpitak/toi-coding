#include <stdio.h>
int main()
{
    int f, m, e;
    scanf("%d", &f);
    scanf("%d", &m);
    scanf("%d", &e);
    if (f >= 5 && m >= 20 && e >= 25)
        printf("pass\n");
    else
        printf("fail\n");
    return 0;
}
