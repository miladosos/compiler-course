#include "global.h"

#ifndef COMPILER_COURSE_LEXAN_H
#define COMPILER_COURSE_LEXAN_H

extern struct IDTables id_tables[IDTABLESBUFFERSIZE];
extern int id_tables_index;

extern struct StringTable string_table[STRINGTABLEBUFFERSIZE];
extern int string_table_index;

extern struct CommentTable comment_table[COMMENTTABLEBUFFERSIZE];
extern int comment_table_index;

void lexan(FILE *filePointer);

int get_or_put_into_id_tables(char *name, int lineNumber);

int put_into_string_table(char *phrase, int lineNumber);

int put_into_comment_table(char *comment, int lineNumber);

#endif //COMPILER_COURSE_LEXAN_H
