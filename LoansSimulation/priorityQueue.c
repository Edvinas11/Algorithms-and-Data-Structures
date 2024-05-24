#include <stdio.h>
#include <stdlib.h>

#include "loans.h"

Node *CreateNode(Loan value, int priority){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->priority = priority; // 1 - principal, 2 - interest and 3 - late interest
    newNode->data = value;
    return newNode;
}
Node *CreatePriorityQueue(){
    Node *head = NULL;
    return head;
}
int isPriorityQueueEmpty(Node *head){
    return head == NULL;
}
void RemoveValue(Node **head){
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
Loan Peek(Node *head){
    return head->data;
}
void Insert(Node **head, Loan value, int priority){
    Node* temp = *head;
    Node* newNode = CreateNode(value, priority);

    if (*head == NULL || priority > (*head)->priority){
        newNode->next = *head;
        *head = newNode;
    } else{
        while (temp->next != NULL && temp->next->priority > priority){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void PrintPriorityQueue(Node *head){
    Node* temp = head;
    if(head == NULL){
        printf("Priority queue is empty\n");
    }
    while(temp != NULL){
        printf("Priority:%d, data:%d\n", temp->priority, temp->data);
        temp = temp->next;
    }
}
void DestroyPriorityQueue(Node *head){
    Node *temp = head->next;
    if(temp != NULL){
        DestroyPriorityQueue(temp);
    }
    free(head);
}
Node* CopyPriorityQueue(Node *head){
    if(head == NULL){
        return NULL;
    }

    Node* newHead = CreateNode(head->data, head->priority);
    Node* current = head->next;
    Node* newCurrent = newHead;

    while (current != NULL) {
        newCurrent->next = CreateNode(current->data, current->priority);
        newCurrent = newCurrent->next;
        current = current->next;
    }

    return newHead;
}

