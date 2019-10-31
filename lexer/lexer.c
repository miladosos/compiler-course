#include "global.h"

void lexan(FILE *file_pointer) {
    int line_number = 1;

    for (char *character = fgetc(file_pointer); character != EOF; character = fgetc(file_pointer)) {
        if (*character == '\n') {
            line_number++;
            continue;
        } else if (isWhitespace(character)) {
            continue;
        } else if (isKey)

    }
}