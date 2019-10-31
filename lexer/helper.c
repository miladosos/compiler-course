#include "global.h"
#include "helper.h"
#include "const.h"

bool isKeyword(char *word[BUFFERSIZE]) {
    int i;
    for (i = 0; i < NELEMS(KEYWORDS); i++) {
        if (strcmp(word, KEYWORDS[i].name) == 0) {
            return true;
        }
    }
    return false;
}

bool isOperator(char *word[BUFFERSIZE]) {
    int i;
    for (i = 0; i < NELEMS(OPERATORS); i++) {
        if (strcmp(word, OPERATORS[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isDelimiter(char *word[BUFFERSIZE]) {
    int i;
    for (i = 0; i < NELEMS(DELIMITERS); i++) {
        if (strcmp(word, DELIMITERS[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isWhitespace(char *word[BUFFERSIZE]) {
    int i;
    for (i = 0; i < NELEMS(WHITESPACES); i++) {
        if (strcmp(word, WHITESPACES[i]) == 0) {
            return true;
        }
    }
    return false;
}

void printer(char *word[BUFFERSIZE], int tokenType) {
    struct Keyword *keyword;
    switch (tokenType) {
        case ERROR:
            printf("ERROR"); // TODO
            return;

        case DONE:
            printf("DONE"); // TODO
            return;

        case KEYWORD:
            keyword = get_keyword(word);
            printf("KEYWORD\t\t%d\n", keyword->id);
            return;

        default:
            printf("DEFAULT"); // TODO
            return;
    }
}

struct Keyword *get_keyword(char *word[BUFFERSIZE]) {
    int i;
    for (i = 0; i < NELEMS(KEYWORDS); i++) {
        if (strcmp(word, KEYWORDS[i].name) == 0) {
            return KEYWORDS[i];
        }
    }

    return NULL;
}
