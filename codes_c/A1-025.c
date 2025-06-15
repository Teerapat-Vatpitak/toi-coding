#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char buf[4];
    scanf("%s", buf);
    int len = strlen(buf);
    char rank[3], suit = buf[len - 1];
    buf[len - 1] = '\0';
    strcpy(rank, buf);
    for (int i = 0; rank[i]; i++)
        rank[i] = tolower(rank[i]);
    char *name;
    if (strcmp(rank, "a") == 0)
        name = "ace";
    else if (strcmp(rank, "j") == 0)
        name = "jack";
    else if (strcmp(rank, "q") == 0)
        name = "queen";
    else if (strcmp(rank, "k") == 0)
        name = "king";
    else
        name = rank;
    char *sname;
    suit = tolower(suit);
    if (suit == 'd')
        sname = "diamonds";
    else if (suit == 'h')
        sname = "hearts";
    else if (suit == 's')
        sname = "spades";
    else
        sname = "clubs";
    printf("%s of %s\n", name, sname);
    return 0;
}
