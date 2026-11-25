/* Stack, circular queue and singly linked list demonstration. */
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5
typedef struct Node { int value; struct Node *next; } Node;

int main(void) {
    int stack[CAPACITY], top = -1;
    stack[++top] = 10; stack[++top] = 20; stack[++top] = 30;
    printf("Stack pop: %d\n", stack[top--]);

    int queue[CAPACITY], front = 0, rear = 0, size = 0;
    int item = 42;
    if (size < CAPACITY) { queue[rear] = item; rear = (rear + 1) % CAPACITY; ++size; }
    if (size > 0) { printf("Queue dequeue: %d\n", queue[front]); front = (front + 1) % CAPACITY; --size; }

    Node *head = NULL;
    int inputs[] = {5, 15, 25};
    for (size_t i = 0; i < sizeof inputs / sizeof inputs[0]; ++i) {
        Node *node = malloc(sizeof *node);
        if (!node) { perror("malloc"); while (head) { Node *next=head->next; free(head); head=next; } return EXIT_FAILURE; }
        node->value = inputs[i]; node->next = head; head = node;
    }
    printf("Linked list: ");
    while (head) { Node *next = head->next; printf("%d ", head->value); free(head); head = next; }
    putchar('\n');
    return 0;
}
