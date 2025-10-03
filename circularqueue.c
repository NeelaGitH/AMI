#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct queue{
    int* values;
    int head, tail, num_entries, size;
} queue;

void init_queue(queue* q, int max_size){
    q->size = max_size;
    q->values = malloc(sizeof(int) * q->size);

    q->num_entries = 0;
    q->head = 0;
    q->tail = 0;
}

bool queue_empty(queue* q){
    return (q->num_entries == 0);
}

bool queue_full(queue* q){
    return (q->num_entries == q->size);
}

void queue_destroy(queue* q){
    free(q->values);
}
bool enqueue(queue* q, int value){
    if (queue_full(q)) return false;

    q->values[q->tail] = value;
    q->num_entries++;

    q->tail = (q->tail + 1) % q->size;
    return true;

}

int dequeue(queue* q){
    if (queue_empty(q)) return QUEUE_EMPTY;

    q->num_entries--;
    int result = q->values[q->head];

    q->head = (q->head + 1) % q->size;

    return result;

}

int main(){

   queue q1;
   init_queue(&q1, 5);

   enqueue(&q1, 34);
   enqueue(&q1, 56);
   enqueue(&q1, 89);
   enqueue(&q1, 78);
   enqueue(&q1, 34);
   enqueue(&q1, 57);

   int t;

   while ((t = dequeue(&q1)) != QUEUE_EMPTY){
        printf("%d removed\n", t);
   }

   queue_destroy(&q1);
}