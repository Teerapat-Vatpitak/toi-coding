#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char a[1001], b[1001];
    if (!fgets(a, sizeof(a), stdin))
        return 0;
    if (!fgets(b, sizeof(b), stdin))
        return 0;
    a[strcspn(a, "\n")] = 0;
    b[strcspn(b, "\n")] = 0;

    int la = strlen(a), lb = strlen(b);
    if (la < lb)
    {
        int orig = la;
        for (int i = 0; i < lb - orig; i++)
            a[orig + i] = a[i % orig];
        a[lb] = '\0';
        la = lb;
    }
    else if (lb < la)
    {
        int orig = lb;
        for (int i = 0; i < la - orig; i++)
            b[orig + i] = b[i % orig];
        b[la] = '\0';
        lb = la;
    }
    int n = la; // now la == lb

    char res[2005];
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        char ca = tolower(a[i]), cb = tolower(b[i]);
        if (ca == 'l' || ca == 'o' || ca == 'v' || ca == 'e' ||
            cb == 'l' || cb == 'o' || cb == 'v' || cb == 'e')
            res[m++] = 'w';
        else
            res[m++] = '$';
    }

    int total_w = 0, max_run = 0, run = 0;
    for (int i = 0; i < m; i++)
    {
        if (res[i] == 'w')
        {
            total_w++;
            run++;
            if (run > max_run)
                max_run = run;
        }
        else
        {
            run = 0;
        }
    }

    if (total_w % 2 == 1)
    {
        char buf[12];
        int len = sprintf(buf, "%d", max_run);
        for (int i = 0; i < len; i++)
            res[m++] = buf[i];
    }
    else if (max_run < 2)
    {
        res[m++] = '#';
    }
    res[m] = '\0';

    printf("%s\n", res);
    return 0;
}
