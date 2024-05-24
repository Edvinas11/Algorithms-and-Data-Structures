#ifndef LOANS_H
#define LOANS_H

typedef struct Loan {
    float amount;
    int period;
    float interestRate;
    float lateInterestRate;
    float remainingDebt;
} Loan;

typedef struct Node{
    int priority;
    Loan data;
    struct Node *next;
} Node;

typedef struct Queue {
    int front;
    int rear;
    int size;
    int capacity;
    Loan *array;
} Queue;

Loan IssueLoan(float amount, int period, float interestRate, float lateInterestRate);
void SettleOldestDebts(Queue *loans, float availableCash);
void SettleDebtsByPriority(Node* priorityLoans, float availableCash);

// Module owner: edbu0238
Queue* CreateQueue();
int isQueueEmpty(Queue *queue);
void Enqueue(Queue *queue, Loan data);
Loan Dequeue(Queue *queue);
Loan GetFrontData(Queue *queue);
int GetQueueSize(Queue *queue);
void DestroyQueue(Queue **queuePointer);

// Module owner: pana9997
Node *CreateNode(Loan value, int priority);
Node *CreatePriorityQueue();
int isPriorityQueueEmpty(Node *head);
void RemoveValue(Node **head);
Loan Peek(Node *head);
void Insert(Node **head, Loan value, int priority);
void PrintPriorityQueue(Node *head);
void DestroyPriorityQueue(Node *head);
Node* CopyPriorityQueue(Node *head);

#endif 