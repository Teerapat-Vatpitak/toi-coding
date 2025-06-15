#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int c10 = n / 10;
    n %= 10;
    int c5 = n / 5;
    n %= 5;
    int c2 = n / 2;
    n %= 2;
    int c1 = n;
    printf("10 = %d\n", c10);
    printf("5 = %d\n", c5);
    printf("2 = %d\n", c2);
    printf("1 = %d\n", c1);
    return 0;
}