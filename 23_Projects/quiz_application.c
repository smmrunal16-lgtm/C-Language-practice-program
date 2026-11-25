/* Multiple-choice quiz with score calculation. */
#include <stdio.h>
int main(void) {
    const char *questions[] = {
        "Which header declares printf?\n1. stdio.h  2. stdlib.h  3. string.h",
        "Which operator gives an address?\n1. *  2. &  3. %"
    };
    const int answers[] = {1, 2};
    int score = 0, choice;
    for (int i = 0; i < 2; ++i) {
        printf("\nQ%d. %s\nAnswer: ", i + 1, questions[i]);
        if (scanf("%d", &choice) != 1) return 1;
        if (choice == answers[i]) { puts("Correct!"); ++score; }
        else printf("Incorrect. Correct answer: %d\n", answers[i]);
    }
    printf("\nFinal score: %d/2\n", score);
    return 0;
}
