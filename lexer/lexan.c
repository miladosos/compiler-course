#include "global.h"
#include "helper.h"
#include "lexan.h"

struct IDTables id_tables[IDTABLESBUFFERSIZE];
int id_tables_index = 0;

struct StringTable string_table[STRINGTABLEBUFFERSIZE];
int string_table_index = 0;

struct CommentTable comment_table[COMMENTTABLEBUFFERSIZE];
int comment_table_index = 0;

void lexan(FILE *filePointer) {
    printer("", -1, LEXERTSTARTINGTOKEN);
    int lineNumber = 1;
    for (char character = fgetc(filePointer); character != EOF; character = fgetc(filePointer)) {
        char characterPtr[2] = {character};
        if (character == '\n') {
            lineNumber++;
            continue;

        } else if (isWhitespace(characterPtr)) {
            continue;

        } else if (character == '/') {
            fgetc(filePointer);

            char *comment = get_line(filePointer, lineNumber);
            int comment_index = put_into_comment_table(comment, lineNumber);

            printer(comment, comment_index, COMMENTTOKEN);
            continue;

        } else if (isalpha(character) || character == '_') {
            ungetc(character, filePointer);
            char *word = get_word(filePointer, lineNumber);
            if (isKeyword(word)) {
                printer(word, -1, KEYWORDTOKEN);
                continue;

            } else {
                int word_index = get_or_put_into_id_tables(word, lineNumber);

                printer(word, word_index, IDTOKEN);
                continue;

            }
        } else if (character == '"' || character == '\'') {
            ungetc(character, filePointer);
            char *phrase = get_phrase(filePointer, lineNumber);

            int word_index = put_into_string_table(phrase, lineNumber);

            printer(phrase, word_index, STRINGTOKEN);
            continue;

        } else {
            if (isDelimiter(characterPtr)) {
                characterPtr[1] = fgetc(filePointer);
                if (!isDelimiter(characterPtr)) {
                    ungetc(characterPtr[1], filePointer);
                    characterPtr[1] = 0;
                }

                printer(characterPtr, -1, DELIMITERTOKEN);
                continue;

            } else if (isOperator(characterPtr)) {
                characterPtr[1] = fgetc(filePointer);
                if (!isOperator(characterPtr)) {
                    ungetc(characterPtr[1], filePointer);
                    characterPtr[1] = 0;
                }
                printer(characterPtr, -1, OPERATORTOKEN);
                continue;
            }
        }
    }
}

int get_or_put_into_id_tables(char *name, int lineNumber) {
    int i;
    for (i = 0; i < id_tables_index; i++) {
        if (strcmp(id_tables[i].value, name) == 0) {
            return id_tables[i].id;
        }
    }
    if (i == IDTABLESBUFFERSIZE) {
        raise_error("ID Tables overflow", lineNumber);
    }

    id_tables[id_tables_index].id = id_tables_index + 1;
    id_tables[id_tables_index].value = name;

    return ++id_tables_index;
}

int put_into_string_table(char *phrase, int lineNumber) {
    if (string_table_index >= STRINGTABLEBUFFERSIZE) {
        raise_error("String Table overflow", lineNumber);
    }

    string_table[string_table_index].id = string_table_index + 1;
    string_table[string_table_index].value = phrase;

    return ++string_table_index;
}

int put_into_comment_table(char *comment, int lineNumber) {
    if (comment_table_index >= COMMENTTABLEBUFFERSIZE) {
        raise_error("Comment Table overflow", lineNumber);
    }

    comment_table[comment_table_index].id = comment_table_index + 1;
    comment_table[comment_table_index].value = comment;

    return ++comment_table_index;
}
