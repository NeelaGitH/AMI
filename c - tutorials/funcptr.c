#include <stdio.h>


double add(double x, double y){
    return x + y;
}

double subtract(double x, double y){
    return x - y;
}

double multiply(double x, double y){
    return x * y;
}

double divide(double x, double y){
    return x / y;
}



int main(){

    int op;
    printf("enter operation: (0 for add, 1 for subtract, 2 for multiply, 3 for divide):\n");
    scanf("%d", &op);

    double op1, op2;
    printf("enter operand 1:\n");
    scanf("%lf", &op1);

    printf("enter operand 2:\n");
    scanf("%lf", &op2);

    double (*array[])(double, double) = {&add, &subtract, &multiply, &divide};
    double res = (*array[op])(op1, op2);

    printf("%lf is the result\n", res);
}