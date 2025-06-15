#include <stdio.h>

int main(){
    char c[6];

    for(int i=0; i<5; i++){
        scanf("%c", &c);
    }

    for(int i=0; i<5; i++){
        printf("%c", c);
    }
}
