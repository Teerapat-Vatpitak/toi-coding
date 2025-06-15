#include <stdio.h>
int main()
{
    int month, day;
    scanf("%d", &month);
    scanf("%d", &day);
    if ((month == 12 && day >= 21) || month == 1 || month == 2 || (month == 3 && day < 21))
        printf("winter\n");
    else if ((month == 3 && day >= 21) || month == 4 || month == 5 || (month == 6 && day < 21))
        printf("spring\n");
    else if ((month == 6 && day >= 21) || month == 7 || month == 8 || (month == 9 && day < 21))
        printf("summer\n");
    else
        printf("fall\n");
    return 0;
}
