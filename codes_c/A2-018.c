#include <stdio.h>
int main()
{
    char c;
    int n;
    if (scanf(" %c %d", &c, &n) != 2)
        return 0;
    const char *col[3] = {"Red", "Green", "Blue"};
    int start = (c == 'R' ? 0 : (c == 'G' ? 1 : 2));
    for (int i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        printf("%s", col[(start + i) % 3]);
    }
    printf("\n");
    return 0;
}
