#ifndef DK_TOOL_H
#define DK_TOOL_H

void input_matrix(int **matrix, int size);
void output_matrix(int **matrix, int size);
int **allocate_matrix(int size);
void free_matrix(int **matrix, int size);
void addition_matrices(int **matrix1, int **matrix2, int **result, int size);

#endif

