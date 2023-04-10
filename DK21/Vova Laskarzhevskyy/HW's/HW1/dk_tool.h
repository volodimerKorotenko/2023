#ifndef DK_TOOL_H_INCLUDED

#define DK_TOOL_H_INCLUDED

int *allocate_mem4num(void);
char *allocate_mem4str(void);
void free_mem4num(int *arr);
void free_mem4str(char *str);
void input_dec_num(int num);
void alg4conv_bin2dec(int num, int *arr);

#endif
