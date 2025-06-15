#include <stdio.h>
int main()
{
    int choice, total = 0;
    while (scanf("%d", &choice) == 1)
    {
        if (choice == 5)
            break;
        if (choice == 1)
            total += 100;
        else if (choice == 2)
            total += 120;
        else if (choice == 3)
            total += 200;
        else if (choice == 4)
            total += 60;
    }
    printf("Bye Bye\nTotal Calories: %d\n", total);
    return 0;
}
