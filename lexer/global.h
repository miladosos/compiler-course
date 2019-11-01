#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef COMPILER_COURSE_GLOBAL_H
#define COMPILER_COURSE_GLOBAL_H

#define BUFFERSIZE  256
#define STRINGBUFFERSIZE 256
#define IDTABLESBUFFERSIZE 256
#define STRINGTABLEBUFFERSIZE 256
#define COMMENTTABLEBUFFERSIZE 256
#define COMMENTBUFFERSIZE 512

#define KEYWORDSCOUNT 15
#define OPERATORSCOUNT 21
#define WHITESPACESCOUNT 3
#define DELIMITERSCOUNT 8

#define LEXERTSTARTINGTOKEN 100
#define KEYWORDTOKEN 101
#define OPERATORTOKEN 102
#define DELIMITERTOKEN 103
#define IDTOKEN 104
#define STRINGTOKEN 105
#define COMMENTTOKEN 106

struct Keyword {
    char *value;
    int id;
};

struct IDTables {
    char *value;
    int id;
};

struct StringTable {
    char *value;
    int id;
};

struct CommentTable {
    char *value;
    int id;
};

#endif //COMPILER_COURSE_GLOBAL_H
