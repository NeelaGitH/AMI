#include <stdio.h>
#include <stdbool.h>

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

double (*select_op())(double, double){
    int op;
    printf("enter operation: (0 for add, 1 for subtract, 2 for multiply, 3 for divide):\n");
    scanf("%d", &op);

    if (op == 0) return add;
    else if (op == 1) return subtract;
    else if (op == 2) return multiply;
    else return divide;
}

bool freeze_C(int val){
    if (val <= 0) return true;
    else return false;
}

bool freeze_F(int val){
    if (val <= 32) return true;
    else return false;
}

void isfreezing(bool (*freeze)(int)){
    int temp = 0;
    printf("Enter temp:\n");
    scanf("%d", &temp);

    if (freeze(temp) == 0) printf("not freezing\n");
    else printf("freezing!\n");
}

int main(){
    //double (*operation)(double, double) = select_op();
    //printf("%lf", operation(3.4, 5.6));

    isfreezing(freeze_C);
    isfreezing(freeze_F);
    return 0;
}