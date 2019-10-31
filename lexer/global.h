#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef COMPILER_COURSE_GLOBAL_H
#define COMPILER_COURSE_GLOBAL_H

#define BUFFERSIZE  256
#define EOS    '\0'
#define NONE   -1

#define DOING 100
#define DONE 101
#define ERROR 102
#define KEYWORD 103
#define OPERATOR 104
#define DELIMITER 105

#endif //COMPILER_COURSE_GLOBAL_H

extern int tokenval;   /*  value of token attribute */
extern int lineno;

struct entry {  /*  form of symbol table entry  */
    char *lexptr;
    int token;
};

extern struct entry symtable[];  /* symbol table  */
void emit(int t, int tval);  /*  generates output  */
void error(char *m);  /* generates all error messages  */
