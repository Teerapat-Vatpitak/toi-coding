#include <stdio.h>
int main()
{
    int n, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char ch;
        scanf(" %c", &ch);
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            c++;
    }
    printf("%d\n", c);
    return 0;
}
