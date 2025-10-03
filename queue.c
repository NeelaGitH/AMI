#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node{
    int value;
    struct node* next;
} node;

typedef struct queue{
    node* head;
    node* tail;
} queue;

void init_queue(queue* q){
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue* q, int value){
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL) return false;

    newNode->value = value;
    newNode->next = NULL;
    if (q->head == NULL){
        q->head = newNode;
        q->tail = newNode;
    }
    else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    return true;
}

int dequeue(queue* q){
    if (q->head == NULL) return QUEUE_EMPTY;

    int element = q->head->value;
    node* tmp = q->head;

    q->head = q->head->next;
    if (q->head == NULL) q->tail = NULL;

    free(tmp);
    return element;

}

int main(){

   queue* q1 = malloc(sizeof(queue));
   init_queue(q1);

   enqueue(q1, 34);
   enqueue(q1, 56);
   enqueue(q1, 89);

   int t;

   while ((t = dequeue(q1)) != QUEUE_EMPTY){
        printf("%d removed\n", t);
   }
}