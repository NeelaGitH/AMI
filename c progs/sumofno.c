#include <stdio.h>
#include <string.h>

int gcd(int a, int b){
    if (b == 0)return a;
    else gcd(b, a%b);
}

int main(){

    printf("%d", gcd(3, 6));
    return 0;
}