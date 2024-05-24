#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node Node;
typedef struct Queue Queue;

Queue* CreateQueue();
int isQueueEmpty(Queue *queue);
void Enqueue(Queue *queue, int data);
int Dequeue(Queue *queue);
int GetFrontData(Queue *queue);
int GetQueueSize(Queue *queue);
void DestroyQueue(Queue **queuePointer);

#endif