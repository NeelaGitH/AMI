// Write a Program to check whether a number is prime or not.

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    scanf("%d", &num);

    for (int i = 2; i*i <= num; i++){
        if (num%i == 0) {
            printf("%d is Not prime", num);
            exit(0);
        }
    }
    printf("%d is Prime", num);

    return 0;
}

