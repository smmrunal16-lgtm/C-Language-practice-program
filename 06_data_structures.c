/*
 * 06_data_structures.c
 * Stack, circular queue, linked list and binary search tree.
 * Build: gcc -std=c11 -Wall -Wextra -Wpedantic 06_data_structures.c -o structures
 */
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

typedef struct { int data[CAPACITY]; int top; } Stack;
static void push(Stack *s, int value) {
    if (s->top == CAPACITY - 1) { puts("Stack overflow"); return; }
    s->data[++s->top] = value;
}
static int pop(Stack *s) {
    if (s->top == -1) { puts("Stack underflow"); return -1; }
    return s->data[s->top--];
}

typedef struct { int data[CAPACITY]; int front, rear, size; } Queue;
static void enqueue(Queue *q, int value) {
    if (q->size == CAPACITY) { puts("Queue full"); return; }
    q->rear = (q->rear + 1) % CAPACITY;
    q->data[q->rear] = value;
    q->size++;
}
static int dequeue(Queue *q) {
    if (q->size == 0) { puts("Queue empty"); return -1; }
    int value = q->data[q->front];
    q->front = (q->front + 1) % CAPACITY;
    q->size--;
    return value;
}

typedef struct Node { int value; struct Node *next; } Node;
static Node *list_insert_front(Node *head, int value) {
    Node *node = malloc(sizeof *node);
    if (!node) { perror("malloc"); return head; }
    node->value = value; node->next = head;
    return node;
}
static void list_print(const Node *head) {
    for (; head; head = head->next) printf("%d -> ", head->value);
    puts("NULL");
}
static void list_free(Node *head) {
    while (head) { Node *next = head->next; free(head); head = next; }
}

typedef struct Tree { int value; struct Tree *left, *right; } Tree;
static Tree *bst_insert(Tree *root, int value) {
    if (!root) {
        Tree *node = calloc(1, sizeof *node);
        if (!node) { perror("calloc"); return NULL; }
        node->value = value; return node;
    }
    if (value < root->value) root->left = bst_insert(root->left, value);
    else if (value > root->value) root->right = bst_insert(root->right, value);
    return root;
}
static void bst_inorder(const Tree *root) {
    if (!root) return;
    bst_inorder(root->left); printf("%d ", root->value); bst_inorder(root->right);
}
static void bst_free(Tree *root) {
    if (!root) return;
    bst_free(root->left); bst_free(root->right); free(root);
}

int main(void) {
    Stack stack = {.top = -1};
    push(&stack, 10); push(&stack, 20);
    printf("Stack pop: %d\n", pop(&stack));

    Queue queue = {.front = 0, .rear = -1, .size = 0};
    enqueue(&queue, 100); enqueue(&queue, 200);
    printf("Queue dequeue: %d\n", dequeue(&queue));

    Node *head = NULL;
    head = list_insert_front(head, 30);
    head = list_insert_front(head, 20);
    head = list_insert_front(head, 10);
    printf("Linked list: "); list_print(head);
    list_free(head);

    Tree *root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (size_t i = 0; i < sizeof values / sizeof values[0]; ++i)
        root = bst_insert(root, values[i]);
    printf("BST inorder (sorted): "); bst_inorder(root); putchar('\n');
    bst_free(root);
    return 0;
}
