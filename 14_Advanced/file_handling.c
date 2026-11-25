/* Text and binary file operations: write, read, append. */
#include <stdio.h>
#include <stdlib.h>

typedef struct { int id; double score; } Record;

int main(void) {
    FILE *file = fopen("practice.txt", "w");
    if (!file) { perror("practice.txt"); return EXIT_FAILURE; }
    fputs("C file handling\n", file);
    if (fclose(file) != 0) { perror("fclose"); return EXIT_FAILURE; }

    file = fopen("practice.txt", "a");
    if (!file) { perror("append"); return EXIT_FAILURE; }
    fputs("Append mode adds this line.\n", file);
    fclose(file);

    file = fopen("practice.txt", "r");
    if (!file) { perror("read"); return EXIT_FAILURE; }
    char line[128];
    puts("Text file contents:");
    while (fgets(line, sizeof line, file)) fputs(line, stdout);
    fclose(file);

    Record original = {101, 92.5}, loaded = {0, 0.0};
    file = fopen("record.bin", "wb");
    if (!file) { perror("binary write"); return EXIT_FAILURE; }
    if (fwrite(&original, sizeof original, 1, file) != 1) {
        fclose(file); fputs("Binary write failed\n", stderr); return EXIT_FAILURE;
    }
    fclose(file);

    file = fopen("record.bin", "rb");
    if (!file) { perror("binary read"); return EXIT_FAILURE; }
    if (fread(&loaded, sizeof loaded, 1, file) != 1) {
        fclose(file); fputs("Binary read failed\n", stderr); return EXIT_FAILURE;
    }
    fclose(file);
    printf("Binary record: id=%d score=%.1f\n", loaded.id, loaded.score);
    return EXIT_SUCCESS;
}
