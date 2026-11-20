#include <stdio.h>

int main(void) {
    const char *filename = "practice.txt";
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }
    if (fprintf(file, "Learning file handling in C.\\n") < 0) {
        perror("Write failed");
        fclose(file);
        return 1;
    }
    if (fclose(file) != 0) {
        perror("Close failed");
        return 1;
    }
    printf("Wrote data to %s\\n", filename);
    return 0;
}
