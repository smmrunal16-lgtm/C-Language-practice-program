/* Student record manager using a text file. */
#include <stdio.h>
#include <stdlib.h>
typedef struct { int roll; char name[40]; float marks; } Student;
int main(void) {
    int choice;
    do {
        printf("\n1.Add student 2.List students 0.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;
        if (choice == 1) {
            Student s;
            printf("Roll: "); if (scanf("%d", &s.roll) != 1) return 1;
            printf("Name (no spaces): "); if (scanf("%39s", s.name) != 1) return 1;
            printf("Marks: "); if (scanf("%f", &s.marks) != 1) return 1;
            FILE *f = fopen("students.txt", "a");
            if (!f) { perror("students.txt"); return 1; }
            fprintf(f, "%d %s %.2f\n", s.roll, s.name, s.marks); fclose(f);
        } else if (choice == 2) {
            Student s; FILE *f = fopen("students.txt", "r");
            if (!f) { puts("No records yet."); continue; }
            while (fscanf(f, "%d %39s %f", &s.roll, s.name, &s.marks) == 3)
                printf("%d %-20s %.2f\n", s.roll, s.name, s.marks);
            fclose(f);
        }
    } while (choice != 0);
    return 0;
}
