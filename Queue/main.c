#include <stdio.h>
#include "queue.h"

int main(){
    int data;
    Queue *queue = CreateQueue();
    printf("Queue size: %d\n", GetQueueSize(queue));

    printf("Empty status: %d\n", isQueueEmpty(queue));

    Enqueue(queue, 1);
    printf("Queue size: %d\n", GetQueueSize(queue));
    Enqueue(queue, 2);
    printf("Queue size: %d\n", GetQueueSize(queue));
    Enqueue(queue, 3);
    printf("Queue size: %d\n", GetQueueSize(queue));
    printf("Empty status: %d\n", isQueueEmpty(queue));

    printf("Dequeing: %d\n", Dequeue(queue));
    printf("Queue size: %d\n", GetQueueSize(queue));
    printf("Dequeing: %d\n", Dequeue(queue));
    printf("Queue size: %d\n", GetQueueSize(queue));

    Enqueue(queue, 4);
    printf("Queue size: %d\n", GetQueueSize(queue));
    Enqueue(queue, 5);
    printf("Queue size: %d\n", GetQueueSize(queue));

    data = GetFrontData(queue);
    printf("Front: %d\n", data);

    DestroyQueue(&queue);

    return 0;
}