#include <stdio.h>
#include <stdlib.h>

void factorize(int number) {
    for (int i = 2; i <= number / 2; i++) {
        if (number % i == 0) {
            printf("%d=%d*%d\n", number, i, number / i);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, file) != -1) {
        int number = atoi(line);
        factorize(number);
    }

    if (line) {
        free(line);
    }
    fclose(file);

    return 0;
}
