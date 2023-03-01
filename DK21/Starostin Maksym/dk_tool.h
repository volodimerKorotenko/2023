#ifndef DK_TOOL_H_INCLUDED
#define DK_TOOL_H_INCLUDED

int **allocateMatrix(int rows, int cols);
void freeMatrix(int **matrix);
void transposeMatrix(int rows, int cols, int **matrix);
void printMatrix(int rows, int cols, int **matrix);
void fillMatrix(int rows, int cols, int **matrix);

#endif // DK_TOOL_H_INCLUDED

