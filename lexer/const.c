

#include "global.h"
#include "const.h"

const char *OPERATORS[OPERATORSCOUNT] = {"++", "--",
                                         "-", "!",
                                         "^",
                                         "*", "/", "%",
                                         "+", "-",
                                         "<", "<=", ">", ">=", "==", "!=",
                                         "&", "|",
                                         "&&", "||",
                                         "=",
};

const char *DELIMITERS[DELIMITERSCOUNT] = {
        ":", ";",
        "(", ")",
        "{", "}",
        "[", "]",
};

const struct Keyword KEYWORDS[KEYWORDSCOUNT] = {
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

const char *WHITESPACES[WHITESPACESCOUNT] = {
        " ", "\t", "\n",
};


const struct Keyword KEYWORDNOTFOUND = {"not found",
                                        -404};