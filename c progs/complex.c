#include <stdio.h>
#include <stdlib.h>

typedef struct complex {
    float real;
    float img;
} complex;

complex* complexsum(complex* c1, complex* c2){
    complex* res = malloc(sizeof(complex));
    res->real = c1->real + c2->real;
    res->img = c1->img + c2->img;

    return res;
}

int main(){
    complex c1, c2;
    printf("enter details abt first complex no:");
    printf("\nenter real part:");
    scanf("%f", &c1.real);
    printf("\nenter img part:");
    scanf("%f", &c1.img);

    printf("\nenter details abt second complex no:");
    printf("\nenter real part:");
    scanf("%f", &c2.real);
    printf("\nenter img part:");
    scanf("%f", &c2.img);

    complex* res = complexsum(&c1, &c2);

    printf("\nSum is %.2f + i%.2f", res->real, res->img);
}