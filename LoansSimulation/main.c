#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include "loans.h"

int main(int argc, char* argv[]){
    FILE* fileName = fopen(argv[1], "r");

    if (fileName == NULL) {
        printf("Can't open file.\n");
        return 1;
    }

    float availableCash = 0.0;
    float interestRate = 0.0;
    float lateInterestRate = 0.0;
    int loanNumber = 0;

    fscanf(fileName, "%f %f %f %d", &availableCash, &interestRate, &lateInterestRate, &loanNumber);

    Queue* loans = CreateQueue();
    Node* priorityLoans = CreatePriorityQueue();

    srand(time(NULL));

    // Simulate data
    for (int i = 0; i < loanNumber; ++i) {
        int loanAmount = rand() % 10000 + 100;
        int period = 30 * (rand() % 10 + 1);
        Enqueue(loans, IssueLoan(loanAmount, period, interestRate, lateInterestRate));
    }

    for (int i = 0; i < loanNumber; ++i) {
        int loanAmount = rand() % 10000 + 100;
        int period = 30 * (rand() % 10 + 1);
        int priority = rand() % 3 + 1;
        Insert(&priorityLoans, IssueLoan(loanAmount, period, interestRate, lateInterestRate), priority);
    }

    printf("Starting simulation with these parameters:\n");
    printf("Client's available cash: %0.2lf\n", availableCash);
    printf("Client's loans number: %d\n\n", GetQueueSize(loans));

    // First strategy
    SettleOldestDebts(loans, availableCash);

    // Second strategy
    SettleDebtsByPriority(priorityLoans, availableCash);

    return 0;
}