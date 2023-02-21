#ifndef DK_TOOL_H
#define DK_TOOL_H

int count_substring(char *string, char *substring);
void print_count(int count);
char *allocate_string(void);
char *allocate_substring(void);
void free_str(char *string);
void free_substr(char *substring);

#endif
