//Write a C program to calculate Compound Interest.

#include <stdio.h>
#include <math.h>

int main(){
    float P;
    printf("enter principal:\t");
    scanf("%f", &P);
    
    int t;
    printf("\nenter time in years:\t");
    scanf("%d", &t);

    float rate;
    printf("\nenter rate in percent:\t");
    scanf("%f", &rate);

    int n;
    printf("\nenter compounding periods:\t");
    scanf("%d", &n);

    float ci = P * pow((1 + rate/100 * n), t * n) - P;
    printf("%f is the CI", ci);
    return 0;
}