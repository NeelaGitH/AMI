#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define STACK_LENGTH 5
#define EMPTY -1
#define STACK_EMPTY INT_MIN

typedef struct stack {
    int stack[STACK_LENGTH];
    int top;
} stack;


bool push(stack* stack_ptr, int value){
    if (stack_ptr->top < STACK_LENGTH - 1){
        stack_ptr->top++;
        stack_ptr->stack[stack_ptr->top] = value;
        return true;
    }
    return false;
}

int pop(stack* stack_ptr){
    if (stack_ptr->top == EMPTY) return STACK_EMPTY;
    int element = stack_ptr->stack[stack_ptr->top];
    stack_ptr->top--;
    return element;
}

int main(){

    stack* s1 = malloc(sizeof(stack));
    s1->top = EMPTY;

    push(s1, 98);
    push(s1, 77);
    push(s1, 34);

    int t;

    while ((t = pop(s1)) != STACK_EMPTY){
        printf("%d removed\n", t);
    }
}