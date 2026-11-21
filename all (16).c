#include <stdio.h>
#include <string.h>

int main(void) {
    char text[32];

    if (fgets(text, sizeof text, stdin) == NULL) {
        puts("Input error");
        return 1;
    }

    size_t pos = strcspn(text, "\n");
    if (text[pos] == '\n') {
        text[pos] = '\0';
    }

    if (strlen(text) > 30) {
        puts("Too long");
        return 1;
    }

    size_t digits = 0;
    size_t spaces = 0;

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            digits++;
        } else if (text[i] == ' ') {
            spaces++;
        }
    }

    printf("Цифр: %zu\n", digits);
    printf("Пробелов: %zu\n", spaces);

    return 0;
}
