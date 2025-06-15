#include <stdio.h>

int main()
{
    int L;
    if (scanf("%d", &L) != 1)
        return 0;

    char chr1[1001], chr2[1001];
    for (int i = 0; i < L; i++)
        scanf(" %c", &chr1[i]);
    for (int i = 0; i < L; i++)
        scanf(" %c", &chr2[i]);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int id, pos;
        char g;
        scanf("%d %d %c", &id, &pos, &g);
        if (id == 1)
            chr1[pos] = g;
        else
            chr2[pos] = g;
    }

    for (int i = 0; i < L; i++)
    {
        printf("%c", chr1[i]);
        if (i < L - 1)
            printf(" ");
    }
    printf("\n");
    for (int i = 0; i < L; i++)
    {
        printf("%c", chr2[i]);
        if (i < L - 1)
            printf(" ");
    }
    printf("\n");

    int cnt = 0;
    for (int i = 0; i < L; i++)
    {
        char a = chr1[i], b = chr2[i];
        if (!((a == 'A' && b == 'T') || (a == 'T' && b == 'A') ||
              (a == 'C' && b == 'G') || (a == 'G' && b == 'C')))
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
