/* Small in-memory banking system. Demo only: not for real money or credentials. */
#include <stdio.h>
typedef struct { unsigned long account; char name[40]; double balance; } Account;
int main(void) {
    Account a = {1001, "Sample Customer", 1000.0};
    int choice; double amount;
    do {
        printf("\n1.View 2.Deposit 3.Withdraw 0.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
        case 1: printf("%lu %s Balance: %.2f\n", a.account, a.name, a.balance); break;
        case 2:
            printf("Deposit amount: "); if (scanf("%lf", &amount) != 1) return 1;
            if (amount > 0) a.balance += amount; else puts("Enter a positive amount.");
            break;
        case 3:
            printf("Withdraw amount: "); if (scanf("%lf", &amount) != 1) return 1;
            if (amount > 0 && amount <= a.balance) a.balance -= amount;
            else puts("Invalid amount or insufficient balance.");
            break;
        case 0: puts("Thank you."); break;
        default: puts("Invalid choice.");
        }
    } while (choice != 0);
    return 0;
}
