#include <stdio.h>
#include <stdbool.h>

#include "loans.h"

Loan IssueLoan(float amount, int period, float interestRate, float lateInterestRate){
    Loan loan;
    loan.amount = amount;
    loan.period = period;
    loan.interestRate = interestRate;
    loan.lateInterestRate = lateInterestRate;
    loan.remainingDebt = amount;
    return loan;
}

void SettleOldestDebts(Queue *loans, float availableCash){
    float totalDebtPaid = 0.0;
    int numDefaultedLoans = 0;
    float totalInterestPayments = 0.0;

    while (!isQueueEmpty(loans) && availableCash > 0) {
        Loan currentLoan = GetFrontData(loans);

        // Calculate the interest for the current loan
        float interest = currentLoan.remainingDebt * (currentLoan.interestRate / 365.0) * 30;

        // Calculate the total payment with interest
        float payment = currentLoan.amount / (currentLoan.period / 30.0) + interest;

        // Update the remaining debt
        float remainingDebt = currentLoan.remainingDebt - (payment + interest);

        if (availableCash >= payment) {
            // Pay off the loan completely
            availableCash -= payment;
            totalDebtPaid += payment;
            totalInterestPayments += interest;
            Dequeue(loans);
        } else {
            currentLoan.remainingDebt -= (availableCash - interest);
            totalDebtPaid += availableCash;
            availableCash = 0;
            numDefaultedLoans++;
        }

        // Update total interest payments based on remaining debt
        totalInterestPayments += remainingDebt > 0 ? (remainingDebt * (currentLoan.interestRate / 365.0) * 30) : 0;
    }

    // Output metrics
    printf("----------------- Results of the first STRATEGY -----------------\n");
    printf("Total Debt Paid: %.0f\n", totalDebtPaid);
    printf("Default Risk: %d defaulted loans\n", numDefaultedLoans);
    printf("Interest Payments: %.2f\n", totalInterestPayments);
    printf("-----------------------------------------------------------------\n");
}

void SettleDebtsByPriority(Node* priorityLoans, float availableCash){
    float totalDebtPaid = 0.0;
    int numDefaultedLoans = 0;
    float totalInterestPayments = 0.0;

    while (!isPriorityQueueEmpty(priorityLoans) && availableCash > 0) {
        Loan currentLoan = Peek(priorityLoans);

        // Calculate the interest for the current loan
        float interest = currentLoan.remainingDebt * (currentLoan.interestRate / 365.0) * 30;

        // Calculate the total payment with interest
        float payment = currentLoan.amount / (currentLoan.period / 30.0) + interest;

        // Calculate the remaining debt after payment
        float remainingDebt = currentLoan.remainingDebt - payment + interest;

        // Check if the current loan can be settled
        if (availableCash >= payment) {
            // Pay off the loan completely
            availableCash -= payment;
            totalDebtPaid += payment;
            totalInterestPayments += interest;
            RemoveValue(&priorityLoans);
        } else {
            currentLoan.remainingDebt -= (availableCash - interest);
            totalDebtPaid += availableCash;
            availableCash = 0;
            numDefaultedLoans++;
        }

        // Update total interest payments based on remaining debt
        totalInterestPayments += remainingDebt > 0 ? (remainingDebt * (currentLoan.interestRate / 365.0) * 30) : 0;
    }

    // Output metrics
    printf("----------------- Results of the second STRATEGY ----------------\n");
    printf("Total Debt Paid: %.0f\n", totalDebtPaid);
    printf("Default Risk: %d defaulted loans\n", numDefaultedLoans);
    printf("Interest Payments: %.2f\n", totalInterestPayments);
    printf("-----------------------------------------------------------------\n");
}