#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if (n < 0)
        printf("Error : Please input positive number\n");
    else if (n == 0 || n > 9)
        printf("Error : Out of range\n");
    else
    {
        char *r[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        printf("%s\n", r[n - 1]);
    }
    return 0;
}
