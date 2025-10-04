#include <stdio.h>
#include <math.h>

typedef struct FootInch{
    int foot;
    float inch;
} Measure;

void sum(Measure m1, Measure m2){
    int foot = m1.foot + m2.foot;
    float inch = m1.inch + m2.inch;
    foot += inch/12;
    inch = fmod(inch , 12);

    printf("Distance is %d - feet & %.2f - inches", foot, inch);

}

int main(){
    Measure m1;
    Measure m2;
    printf("enter distance(foot)- 1\n");
    scanf("%d", &m1.foot);
    printf("enter distance(inches)- 1\n");
    scanf("%f", &m1.inch);

    printf("enter distance(foot)- 2\n");
    scanf("%d", &m2.foot);
    printf("enter distance(inches)- 2\n");
    scanf("%f", &m2.inch);

    sum(m1, m2);
}