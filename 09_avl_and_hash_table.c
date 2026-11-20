/*
 * 09_avl_and_hash_table.c
 * Advanced structures: AVL self-balancing BST + open-addressed hash table.
 * Build: gcc -std=c11 -Wall -Wextra -Wpedantic 09_avl_and_hash_table.c -o avl_hash
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct AVLNode {
    int key, height;
    struct AVLNode *left, *right;
} AVLNode;

static int max_int(int a, int b) { return a > b ? a : b; }
static int height(const AVLNode *n) { return n ? n->height : 0; }
static int balance_factor(const AVLNode *n) {
    return n ? height(n->left) - height(n->right) : 0;
}
static AVLNode *new_node(int key) {
    AVLNode *n = malloc(sizeof *n);
    if (!n) { perror("malloc"); return NULL; }
    *n = (AVLNode){.key = key, .height = 1, .left = NULL, .right = NULL};
    return n;
}
static AVLNode *rotate_right(AVLNode *y) {
    AVLNode *x = y->left, *middle = x->right;
    x->right = y; y->left = middle;
    y->height = 1 + max_int(height(y->left), height(y->right));
    x->height = 1 + max_int(height(x->left), height(x->right));
    return x;
}
static AVLNode *rotate_left(AVLNode *x) {
    AVLNode *y = x->right, *middle = y->left;
    y->left = x; x->right = middle;
    x->height = 1 + max_int(height(x->left), height(x->right));
    y->height = 1 + max_int(height(y->left), height(y->right));
    return y;
}
static AVLNode *avl_insert(AVLNode *root, int key) {
    if (!root) return new_node(key);
    if (key < root->key) root->left = avl_insert(root->left, key);
    else if (key > root->key) root->right = avl_insert(root->right, key);
    else return root;
    root->height = 1 + max_int(height(root->left), height(root->right));
    int b = balance_factor(root);
    if (b > 1 && key < root->left->key) return rotate_right(root);
    if (b < -1 && key > root->right->key) return rotate_left(root);
    if (b > 1 && key > root->left->key) {
        root->left = rotate_left(root->left); return rotate_right(root);
    }
    if (b < -1 && key < root->right->key) {
        root->right = rotate_right(root->right); return rotate_left(root);
    }
    return root;
}
static int avl_contains(const AVLNode *root, int key) {
    while (root) {
        if (key == root->key) return 1;
        root = key < root->key ? root->left : root->right;
    }
    return 0;
}
static void avl_print(const AVLNode *root) {
    if (!root) return;
    avl_print(root->left); printf("%d ", root->key); avl_print(root->right);
}
static void avl_free(AVLNode *root) {
    if (!root) return;
    avl_free(root->left); avl_free(root->right); free(root);
}

#define TABLE_SIZE 17
#define EMPTY 0
#define OCCUPIED 1
#define DELETED 2
typedef struct { int key, value; unsigned char state; } Entry;
typedef struct { Entry entries[TABLE_SIZE]; } HashTable;
static size_t hash_int(int key) {
    return (size_t)((uint32_t)key * UINT32_C(2654435761)) % TABLE_SIZE;
}
static int hash_put(HashTable *t, int key, int value) {
    size_t first_deleted = TABLE_SIZE;
    for (size_t step = 0; step < TABLE_SIZE; ++step) {
        size_t i = (hash_int(key) + step) % TABLE_SIZE;
        Entry *e = &t->entries[i];
        if (e->state == OCCUPIED && e->key == key) { e->value = value; return 1; }
        if (e->state == DELETED && first_deleted == TABLE_SIZE) first_deleted = i;
        if (e->state == EMPTY) {
            size_t target = first_deleted == TABLE_SIZE ? i : first_deleted;
            t->entries[target] = (Entry){key, value, OCCUPIED};
            return 1;
        }
    }
    if (first_deleted != TABLE_SIZE) {
        t->entries[first_deleted] = (Entry){key, value, OCCUPIED};
        return 1;
    }
    return 0;
}
static int hash_get(const HashTable *t, int key, int *value) {
    for (size_t step = 0; step < TABLE_SIZE; ++step) {
        size_t i = (hash_int(key) + step) % TABLE_SIZE;
        const Entry *e = &t->entries[i];
        if (e->state == EMPTY) return 0;
        if (e->state == OCCUPIED && e->key == key) {
            *value = e->value; return 1;
        }
    }
    return 0;
}
static int hash_remove(HashTable *t, int key) {
    for (size_t step = 0; step < TABLE_SIZE; ++step) {
        size_t i = (hash_int(key) + step) % TABLE_SIZE;
        Entry *e = &t->entries[i];
        if (e->state == EMPTY) return 0;
        if (e->state == OCCUPIED && e->key == key) {
            e->state = DELETED; return 1;
        }
    }
    return 0;
}
int main(void) {
    AVLNode *root = NULL;
    const int keys[] = {30, 20, 40, 10, 25, 35, 50, 5};
    for (size_t i = 0; i < sizeof keys / sizeof keys[0]; ++i) {
        AVLNode *next = avl_insert(root, keys[i]);
        if (!next) { avl_free(root); return 1; }
        root = next;
    }
    printf("AVL inorder: "); avl_print(root); putchar('\n');
    printf("Contains 25? %s\n", avl_contains(root, 25) ? "yes" : "no");
    avl_free(root);

    HashTable table = {0};
    hash_put(&table, 42, 900); hash_put(&table, 59, 1200);
    int value;
    if (hash_get(&table, 42, &value)) printf("Key 42 => %d\n", value);
    hash_remove(&table, 42);
    printf("Key 42 after delete: %s\n",
           hash_get(&table, 42, &value) ? "found" : "not found");
    return 0;
}
