#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define STACK_LENGTH 5
#define EMPTY -1
#define STACK_EMPTY INT_MIN

typedef struct node{
    int value;
    struct node* next;
} node;

typedef node* stack;

bool push(stack* head_ptr, int value){
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL) return false;
    newNode->value = value;
    newNode->next = *head_ptr;
    *head_ptr = newNode;
    return true;
}

int pop(stack* head_ptr){
    if (*head_ptr == NULL) return STACK_EMPTY;
    int element = (*head_ptr)->value;
    node* temp = (*head_ptr);
    *head_ptr = (*head_ptr)->next;

    free(temp);
    return element;
}

int main(){

    stack s1 = NULL, s2 = NULL;
    push(&s1, 98);
    push(&s2, 77);
    push(&s1, 34);

    int t;

    while ((t = pop(&s1)) != STACK_EMPTY){
        printf("%d removed\n", t);
    }
}