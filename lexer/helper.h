#include "global.h"
#include "const.h"

#ifndef COMPILER_COURSE_HELPER_H
#define COMPILER_COURSE_HELPER_H

bool isKeyword(char word[BUFFERSIZE]);

bool isOperator(char word[BUFFERSIZE]);

bool isDelimiter(char word[BUFFERSIZE]);

bool isWhitespace(char word[BUFFERSIZE]);

void printer(char word[BUFFERSIZE], int index, int tokenType);

char *_allocate_str(char word[BUFFERSIZE], int size);

char *get_word(FILE *filePointer, int lineNumber);

char *get_phrase(FILE *filePointer, int lineNumber);

char *get_line(FILE *filePointer, int lineNumber);

struct Keyword get_keyword(char word[BUFFERSIZE]);

void raise_error(char *err_message, int lineNumber);

#endif // COMPILER_COURSE_HELPER_H