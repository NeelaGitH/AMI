#include <stdio.h>

#define SIZE 88

int main(){
    #ifdef SIZE
    #if SIZE >= 100
    printf("Large buffer\n");
    #else
    printf("Small buffer\n");
    #endif

    #endif
    return 0;
}