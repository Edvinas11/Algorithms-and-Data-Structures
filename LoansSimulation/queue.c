// Module owner: edbu0238
#include <stdio.h>
#include <stdlib.h>

#include "loans.h"

// Function which creates an empty queue and returns pointer to it
Queue* CreateQueue(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->array = (Loan*)malloc(10 * sizeof(Loan));

    if(queue == NULL || queue->array == NULL){
        printf("Failed to allocate memory.\n");
        exit(1);
    }

    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = 10;

    return queue;
}

// Function which returns 1 if queue is empty. Otherwise, it returns 0
int isQueueEmpty(Queue *queue){
    return queue->size == 0;
}

// Function which enqueue an element into the queue
void Enqueue(Queue *queue, Loan data){
    // Increase the capacity of the queue if the queue is full
    if(queue->size == queue->capacity){
        queue->capacity *= 2;
        queue->array = (Loan*)realloc(queue->array, queue->capacity * sizeof(Loan));
    }

    if(isQueueEmpty(queue)){
        queue->front = 0;
    }

    queue->rear++;
    queue->array[queue->rear] = data;
    queue->size++;
}

// Function to dequeue an element from the queue
Loan Dequeue(Queue *queue){
    if(isQueueEmpty(queue)){
        printf("Queue is empty. Dequeue operation failed.\n");
        exit(1);
    }

    Loan data = queue->array[queue->front];
    queue->front++;
    queue->size--;

    return data;
}

// Function which gets the front element of the queue
Loan GetFrontData(Queue *queue){
    if(isQueueEmpty(queue)){
        printf("Queue is empty. Front operation failed.\n");
        exit(1); 
    }

    return queue->array[queue->front];
}

// Function which gets the size of the queue
int GetQueueSize(Queue *queue){
    return queue->size;
}

// Function which destroys the queue
void DestroyQueue(Queue **queuePointer){
    if(queuePointer == NULL || *queuePointer == NULL){
        return;
    }

    Queue *queue = *queuePointer;

    free(queue->array);
    free(queue);

    *queuePointer = NULL;
}