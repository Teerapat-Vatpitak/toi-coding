#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char s[16];
    if (scanf("%15s", s) != 1) return 0;
    int n = strlen(s);

    int maxU = 0;
    for (int i = 0; i < n; i++) {
        if (toupper((unsigned char)s[i]) == 'B') {
            int cnt = 0;
            for (int j = i + 1; j < n && toupper((unsigned char)s[j]) == 'U'; j++) {
                cnt++;
            }
            if (cnt >= 2 && cnt > maxU) maxU = cnt;
        }
    }
    if (maxU > 0) {
        printf("Yes %d\n", maxU);
    } else {
        int posB = -1;
        for (int i = 0; i < n; i++) {
            if (toupper((unsigned char)s[i]) == 'B') {
                posB = i;
                break;
            }
        }
        if (posB >= 0) {
            for (int i = 0; i <= posB; i++) putchar(s[i]);
            for (int i = posB + 1; i < n; i++) putchar('U');
            putchar('\n');
        } else {
            static const char *pat = "BUU";
            for (int i = 0; i < n; i++) putchar(pat[i % 3]);
            putchar('\n');
        }
    }
    return 0;
}
