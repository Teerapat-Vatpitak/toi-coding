#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char s[1001];
    if (scanf("%1000s", s) != 1)
        return 0;
    int n = strlen(s);

    // 1) Validate and check “only I/T”
    int onlyIT = 1;
    for (int i = 0; i < n; i++)
    {
        char c = toupper((unsigned char)s[i]);
        if (c != 'R' && c != 'A' && c != 'B' && c != 'I' && c != 'T')
        {
            printf("no %d\n", i);
            return 0;
        }
        if (c != 'I' && c != 'T')
        {
            onlyIT = 0;
        }
    }
    if (onlyIT)
    {
        printf("unknown %d\n", n);
        return 0;
    }

    // 2) Pattern‐check R→A runs, A after R/A, B→I/T
    for (int i = 0; i < n; i++)
    {
        char c = toupper((unsigned char)s[i]);
        if (c == 'R')
        {
            int idx = (i + 1 < n ? i + 1 : i);
            char nxt = (i + 1 < n ? toupper((unsigned char)s[i + 1]) : 0);
            if (nxt != 'A')
            {
                printf("no %d\n", idx);
                return 0;
            }
        }
        else if (c == 'A')
        {
            if (i == 0)
            {
                printf("no %d\n", i);
                return 0;
            }
            char prev = toupper((unsigned char)s[i - 1]);
            if (prev != 'R' && prev != 'A')
            {
                printf("no %d\n", i);
                return 0;
            }
        }
        else if (c == 'B')
        {
            int idx = (i + 1 < n ? i + 1 : i);
            char nxt = (i + 1 < n ? toupper((unsigned char)s[i + 1]) : 0);
            if (nxt != 'I' && nxt != 'T')
            {
                printf("no %d\n", idx);
                return 0;
            }
        }
        // I and T have no extra constraints
    }

    // 3) Compute longest A‐run immediately following an ‘R’
    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        if (toupper((unsigned char)s[i]) == 'R')
        {
            int cnt = 0;
            for (int j = i + 1; j < n && toupper((unsigned char)s[j]) == 'A'; j++)
            {
                cnt++;
            }
            if (cnt > maxA)
                maxA = cnt;
        }
    }

    printf("yes %d\n", maxA);
    return 0;
}
