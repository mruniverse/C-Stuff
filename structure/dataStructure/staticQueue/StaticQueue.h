#include <stdio.h>
#include <stdlib.h>

#define MAX 50;

struct Queue{
    int A[MAX];
    int begin;
    int size;
}

void startQueue(struct Queue *q){
    q->begin = 0;
    q->size = 0;
}

int queueSize(struct Queue *q){
    return q->size;
}

void showQueue(struct Queue *q){
    int begin = q->begin;
    for(int i = 0; i < q->size; i++){
        printf("%d\n", q->A[i]);
    }
}
