#include "global.h"
#include "helper.h"
#include "const.h"

bool isKeyword(char word[BUFFERSIZE]) {
    int i;
    for (i = 0; i < KEYWORDSCOUNT; i++) {
        if (strcmp(word, KEYWORDS[i].value) == 0) {
            return true;
        }
    }
    return false;
}

bool isOperator(char word[BUFFERSIZE]) {
    int i;
    for (i = 0; i < OPERATORSCOUNT; i++) {
        if (strcmp(word, OPERATORS[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isDelimiter(char word[BUFFERSIZE]) {
    int i;
    for (i = 0; i < DELIMITERSCOUNT; i++) {
        if (strcmp(word, DELIMITERS[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isWhitespace(char word[BUFFERSIZE]) {
    int i;
    for (i = 0; i < WHITESPACESCOUNT; i++) {
        if (strncmp(word, WHITESPACES[i], 1) == 0) {
            return true;
        }
    }
    return false;
}

char *_allocate_str(char word[BUFFERSIZE], int size) {
    char *result = (char *) malloc(sizeof(char) * size);
    int i;
    for (i = 0; i < size; i++) {
        result[i] = word[i];
    }

    return result;
}

char *get_word(FILE *filePointer, int lineNumber) {
    char result[BUFFERSIZE];
    int i;
    for (i = 0; i < BUFFERSIZE + 1; i++) {
        if (i >= BUFFERSIZE) {
            raise_error("Buffer overflow", lineNumber);
        }

        char c = fgetc(filePointer);
        if (!isalpha(c) && c != '_' && !isdigit(c)) {
            ungetc(c, filePointer);
            return _allocate_str(result, i);
        }

        result[i] = c;
    }

    return NULL;
}

char *get_phrase(FILE *filePointer, int lineNumber) {
    char result[STRINGBUFFERSIZE];
    int i;
    char starting_identifier = fgetc(filePointer);
    for (i = 0; i < STRINGBUFFERSIZE + 2; i++) {
        if (i > STRINGBUFFERSIZE) {
            raise_error("String Buffer overflow", lineNumber);
        }

        char c = fgetc(filePointer);
        if (c == starting_identifier) {
            return _allocate_str(result, i);
        }

        result[i] = c;
    }

    return NULL;
}

char *get_line(FILE *filePointer, int lineNumber) {
    char result[COMMENTBUFFERSIZE];
    int i;
    for (i = 0; i < COMMENTBUFFERSIZE + 1; i++) {
        if (i > COMMENTBUFFERSIZE) {
            raise_error("Comment Buffer overflow", lineNumber);
        }

        char c = fgetc(filePointer);
        if (c == '\n') {
            return _allocate_str(result, i);
        }

        result[i] = c;
    }
}

struct Keyword get_keyword(char word[BUFFERSIZE]) {
    int i;
    for (i = 0; i < KEYWORDSCOUNT; i++) {
        if (strcmp(word, KEYWORDS[i].value) == 0) {
            return KEYWORDS[i];
        }
    }

    return KEYWORDNOTFOUND;
}

void raise_error(char *err_message, int lineNumber) {
    printf("line %d: <%s>", lineNumber, err_message);
    exit(1);
}

void printer(char word[BUFFERSIZE], int index, int tokenType) {
    struct Keyword keyword;
    switch (tokenType) {
        case LEXERTSTARTINGTOKEN:
            printf("---------------- LEX OUTPUT ----------------\n");
            return;

        case KEYWORDTOKEN:
            keyword = get_keyword(word);
            if (keyword.id == KEYWORDNOTFOUND.id && keyword.value == KEYWORDNOTFOUND.value) {
                raise_error("keyword not found", -1);
            }

            printf("KEYWORD\t %d \n", keyword.id);
            return;

        case DELIMITERTOKEN:
        case OPERATORTOKEN:
            printf("%s\t NONE \n", word);
            return;

        case IDTOKEN:
            printf("ID\t %d \t\t //%s \n", index, word);
            return;

        case STRINGTOKEN:
            printf("STRING\t %d \t //address of \"%s\" in strings buffer\n", index, word);
            return;

        case COMMENTTOKEN:
            printf("COMMENT\t %d \t //%s\n", index, word);
            return;

        default:
            raise_error("UNKNOWN TOKEN TYPE", -1);
            return;
    }
}
