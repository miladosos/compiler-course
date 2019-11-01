#include "lexer/global.h"
#include "lexer/lexan.h"

int main() {
    char *FILEPATH = "/path/to/file.b";

    FILE *filePointer = fopen(FILEPATH, "r");
    if (filePointer == NULL) {
        perror("Error while opening file");
        return -1;
    }

    lexan(filePointer);

    return 0;
}
