#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main(void) {
    Node *head = NULL, *tail = NULL;
    int count;
    printf("How many nodes? ");
    if (scanf("%d", &count) != 1 || count < 0 || count > 10000) return 1;

    for (int i = 0; i < count; i++) {
        Node *node = malloc(sizeof *node);
        if (node == NULL) {
            fprintf(stderr, "Memory allocation failed.\\n");
            while (head != NULL) { Node *next = head->next; free(head); head = next; }
            return 1;
        }
        printf("Value %d: ", i + 1);
        if (scanf("%d", &node->data) != 1) {
            free(node);
            while (head != NULL) { Node *next = head->next; free(head); head = next; }
            return 1;
        }
        node->next = NULL;
        if (tail == NULL) head = node;
        else tail->next = node;
        tail = node;
    }

    printf("Linked list: ");
    for (Node *current = head; current != NULL; current = current->next)
        printf("%d -> ", current->data);
    puts("NULL");

    while (head != NULL) { Node *next = head->next; free(head); head = next; }
    return 0;
}
