#ifndef DK_TOOL_H_INCLUDED
#define DK_TOOL_H_INCLUDED

int **crmatrix(int row, int col);
void freematrix(int**matrix, int row);
void printmatrix(int **matrix, int row, int col);
void filling(int **matrix, int row, int col, char *text);
int **rizmatr(int **matrix1, int **matrix2, int row, int col);
int get_dodint(char *text);
int get_int();
int get_inttext(char *text);
#endif // DK_TOOL_H_INCLUDED
