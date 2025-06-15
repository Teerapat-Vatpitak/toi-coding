#include <stdio.h>
int main()
{
    int n;
    char op;
    scanf("%d", &n);
    scanf(" %c", &op);
    int a = n;
    int b = (n / 10) + (n % 10) * 10;
    if (op == '+')
        printf("%d + %d = %d\n", a, b, a + b);
    else
        printf("%d * %d = %d\n", a, b, a * b);
    return 0;
}
