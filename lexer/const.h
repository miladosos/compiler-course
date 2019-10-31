//
// Created by milad on 10/31/19.
//
#include "global.h"

#ifndef COMPILER_COURSE_CONST_H
#define COMPILER_COURSE_CONST_H

#endif //COMPILER_COURSE_CONST_H

const char *OPERATORS[] = {"++", "--",
                           "-", "!",
                           "^",
                           "*", "/", "%",
                           "+", "-",
                           "<", "<=", ">", ">=", "==", "!=",
                           "&&", "||",
                           "="};

const char *DELIMITERS[] = {":", ";"};

struct Keyword {
    char *name;
    int id;
};

const struct Keyword KEYWORDS[] = {
        {"array",    1},
        {"boolean",  2},
        {"char",     3},
        {"else",     4},
        {"false",    5},
        {"for",      6},
        {"function", 7},
        {"if",       8},
        {"integer",  9},
        {"print",    10},
        {"return",   11},
        {"string",   12},
        {"true",     13},
        {"void",     14},
        {"while",    15},
};

const char *WHITESPACES[] = {" ", "\t", "\n"};
