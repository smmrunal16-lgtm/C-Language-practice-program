/* Inventory manager with file-backed stock records. */
#include <stdio.h>
typedef struct { char name[40]; int quantity; double price; } Item;
int main(void) {
    int choice;
    do {
        printf("\n1.Add/update stock record 2.List records 0.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;
        if (choice == 1) {
            Item x;
            printf("Item name (no spaces): "); if (scanf("%39s", x.name) != 1) return 1;
            printf("Quantity and unit price: ");
            if (scanf("%d %lf", &x.quantity, &x.price) != 2 || x.quantity < 0 || x.price < 0) {
                puts("Invalid values."); return 1;
            }
            FILE *f = fopen("inventory.txt", "a");
            if (!f) { perror("inventory.txt"); return 1; }
            fprintf(f, "%s %d %.2f\n", x.name, x.quantity, x.price); fclose(f);
        } else if (choice == 2) {
            Item x; FILE *f = fopen("inventory.txt", "r");
            if (!f) { puts("Inventory is empty."); continue; }
            while (fscanf(f, "%39s %d %lf", x.name, &x.quantity, &x.price) == 3)
                printf("%-20s qty=%d unit=%.2f total=%.2f\n", x.name, x.quantity, x.price, x.quantity*x.price);
            fclose(f);
        }
    } while (choice != 0);
    return 0;
}
