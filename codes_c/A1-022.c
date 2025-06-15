#include <stdio.h>
int main()
{
    int d, m;
    scanf("%d%d", &d, &m);
    if ((m == 12 && d >= 22) || (m == 1 && d <= 19))
        printf("capricorn\n");
    else if ((m == 1 && d >= 20) || (m == 2 && d <= 18))
        printf("aquarius\n");
    else if ((m == 2 && d >= 19) || (m == 3 && d <= 20))
        printf("pisces\n");
    else if ((m == 3 && d >= 21) || (m == 4 && d <= 19))
        printf("aries\n");
    else if ((m == 4 && d >= 20) || (m == 5 && d <= 20))
        printf("taurus\n");
    else if ((m == 5 && d >= 21) || (m == 6 && d <= 21))
        printf("gemini\n");
    else if ((m == 6 && d >= 22) || (m == 7 && d <= 22))
        printf("cancer\n");
    else if ((m == 7 && d >= 23) || (m == 8 && d <= 22))
        printf("leo\n");
    else if ((m == 8 && d >= 23) || (m == 9 && d <= 22))
        printf("virgo\n");
    else if ((m == 9 && d >= 23) || (m == 10 && d <= 23))
        printf("libra\n");
    else if ((m == 10 && d >= 24) || (m == 11 && d <= 21))
        printf("scorpio\n");
    else
        printf("sagittarius\n");
    return 0;
}
