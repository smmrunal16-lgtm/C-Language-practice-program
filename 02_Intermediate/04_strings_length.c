#include <stdio.h>
#include <string.h>

int main(void) {
    char text[100];
    printf("Enter a word or sentence: ");
    if (fgets(text, sizeof text, stdin) == NULL) return 1;
    text[strcspn(text, "\\n")] = '\\0';
    printf("Text: %s\\n", text);
    printf("Length: %zu\\n", strlen(text));
    return 0;
}
