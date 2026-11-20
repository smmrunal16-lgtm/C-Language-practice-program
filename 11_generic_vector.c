/*
 * 11_generic_vector.c
 * Generic resizable vector using void pointers + portable field-wise file I/O.
 * Build: gcc -std=c11 -Wall -Wextra -Wpedantic 11_generic_vector.c -o generic_vector
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    void *data;
    size_t length, capacity, element_size;
} Vector;
static int vector_init(Vector *v, size_t element_size) {
    if (!v || element_size == 0) return 0;
    *v = (Vector){.data = NULL, .length = 0, .capacity = 0,
                  .element_size = element_size};
    return 1;
}
static int vector_reserve(Vector *v, size_t requested) {
    if (requested <= v->capacity) return 1;
    if (requested > SIZE_MAX / v->element_size) return 0;
    size_t cap = v->capacity ? v->capacity : 4;
    while (cap < requested) {
        if (cap > SIZE_MAX / 2) { cap = requested; break; }
        cap *= 2;
    }
    if (cap > SIZE_MAX / v->element_size) return 0;
    void *next = realloc(v->data, cap * v->element_size);
    if (!next) return 0;
    v->data = next; v->capacity = cap;
    return 1;
}
static int vector_push(Vector *v, const void *element) {
    if (!v || !element || v->length == SIZE_MAX ||
        !vector_reserve(v, v->length + 1)) return 0;
    memcpy((unsigned char *)v->data + v->length * v->element_size,
           element, v->element_size);
    ++v->length;
    return 1;
}
static void *vector_at(Vector *v, size_t index) {
    if (!v || index >= v->length) return NULL;
    return (unsigned char *)v->data + index * v->element_size;
}
static void vector_destroy(Vector *v) {
    if (!v) return;
    free(v->data); *v = (Vector){0};
}
typedef struct { int id; double score; } Record;

/* Store fields explicitly: raw struct dumps can contain padding and are
   not a portable file format across compilers or machine architectures. */
static int save_records(const char *path, const Record *records, size_t count) {
    FILE *file = fopen(path, "wb");
    if (!file) { perror("fopen"); return 0; }
    uint32_t n = (uint32_t)count;
    int ok = fwrite(&n, sizeof n, 1, file) == 1;
    for (size_t i = 0; ok && i < count; ++i)
        ok = fwrite(&records[i].id, sizeof records[i].id, 1, file) == 1 &&
             fwrite(&records[i].score, sizeof records[i].score, 1, file) == 1;
    if (fclose(file) != 0) ok = 0;
    return ok;
}
int main(void) {
    Vector numbers;
    if (!vector_init(&numbers, sizeof(int))) return 1;
    for (int i = 1; i <= 8; ++i)
        if (!vector_push(&numbers, &i)) {
            fputs("Could not grow vector\n", stderr);
            vector_destroy(&numbers); return 1;
        }
    printf("Generic vector: ");
    for (size_t i = 0; i < numbers.length; ++i)
        printf("%d ", *(int *)vector_at(&numbers, i));
    putchar('\n');
    vector_destroy(&numbers);

    const Record records[] = {{101, 91.5}, {102, 87.0}, {103, 95.25}};
    if (!save_records("records.bin", records,
                      sizeof records / sizeof records[0])) {
        fputs("Could not save records.bin\n", stderr); return 1;
    }
    puts("Saved 3 records to records.bin (field-wise binary format).");
    return 0;
}
