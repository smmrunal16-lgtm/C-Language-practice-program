/* Contact manager: add and list contacts in a text file. */
#include <stdio.h>
int main(void) {
    int choice;
    do {
        printf("\n1.Add contact 2.List contacts 0.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;
        if (choice == 1) {
            char name[40], phone[20];
            printf("Name (no spaces): "); if (scanf("%39s", name) != 1) return 1;
            printf("Phone: "); if (scanf("%19s", phone) != 1) return 1;
            FILE *f = fopen("contacts.txt", "a");
            if (!f) { perror("contacts.txt"); return 1; }
            fprintf(f, "%s %s\n", name, phone); fclose(f);
        } else if (choice == 2) {
            char name[40], phone[20]; FILE *f = fopen("contacts.txt", "r");
            if (!f) { puts("No contacts yet."); continue; }
            while (fscanf(f, "%39s %19s", name, phone) == 2)
                printf("%-20s %s\n", name, phone);
            fclose(f);
        }
    } while (choice != 0);
    return 0;
}
