#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define pi 22/7

void pyramid(int n){
    for (int i = 1; i <= n; i++){
        //print spaces
        for (int j = 1; j <= n - i; j++){
            printf(" ");
        }

        //print stars
        for (int j = 1; j < 2 * i; j++){
            printf("*");
        }

        printf("\n");
    }

}

int main(){
    pyramid(10);
    
    return 0;
}