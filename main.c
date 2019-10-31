#include "lexer/global.h"


int main() {
    char *FILEPATH = "/path/to/file.b";

    FILE *file_pointer = fopen(FILEPATH, "r");
    if (file_pointer == NULL) {
        perror("Error while opening file");
        return -1;
    }

    lexan(file_pointer);

    return 0;
}
