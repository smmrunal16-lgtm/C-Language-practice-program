/* Basic library issue/return tracker (single sample book, in memory). */
#include <stdio.h>
int main(void) {
    int available = 1, choice;
    do {
        printf("\n1.Show status 2.Issue 3.Return 0.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;
        switch (choice) {
        case 1: puts(available ? "Book is available." : "Book is issued."); break;
        case 2: if (available) { available = 0; puts("Book issued."); } else puts("Already issued."); break;
        case 3: if (!available) { available = 1; puts("Book returned."); } else puts("No issue to return."); break;
        case 0: break;
        default: puts("Invalid choice.");
        }
    } while (choice != 0);
    return 0;
}
