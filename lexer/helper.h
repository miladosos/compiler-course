#include "global.h"
#include "const.h"

#define NELEMS(x) (sizeof(x) / sizeof(x[0]))

bool isKeyword(char *word[BUFFERSIZE]);

bool isOperator(char *word[BUFFERSIZE]);

bool isDelimiter(char *word[BUFFERSIZE]);

bool isWhitespace(char *word[BUFFERSIZE]);

void printer(char *word[BUFFERSIZE], int tokenType);

void get_string(FILE *file_pointer, char *result[256]);

struct Keyword *get_keyword(char *word[BUFFERSIZE]);