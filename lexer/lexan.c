#include "global.h"
#include "helper.h"

void lexan(FILE *file_pointer) {
    int line_number = 1;

    for (char character = fgetc(file_pointer); character != EOF; character = fgetc(file_pointer)) {
        if (character == '\n') {
            line_number++;
            continue;

        } else if (isWhitespace(&character)) {
            continue;

        } else if (isalpha(character) || character == '_') {
            fputc(character, file_pointer);
            char *word[BUFFERSIZE];
            get_string(file_pointer, word);

            if (isKeyword(word)) {
                printer(word, KEYWORD);
                continue;
            } else {
                continue; // TODO
            }
        } else if (isdigit(character)) {
            char *word[BUFFERSIZE];
            ungetc(character, file_pointer);
            fscanf(file_pointer, "%d", word);
            printer(word, )
        }

    }
}

void get_string(FILE *file_pointer, char *result[256]) {
    int i;
    for (i = 0; i < BUFFERSIZE; i++) {
        char c = fgetc(file_pointer);
        if (!isalpha(c)) {
            fputc(c, file_pointer);
            return;
        }
        result[i] = c;
    }
}
