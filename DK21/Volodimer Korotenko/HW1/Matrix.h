#pragma once
void CreateMatrix( int Width, int Height, int** Matrix );
void Render( int Width, int Height, int** Matrix );
void MulMatrixByNumber( int Width, int Height, int** MatrixA, int Number );
void MulMatrixByMatrix( int Size, int** MatrixA, int** MatrixB );
void AddMatrixByMatrix( int Width, int Height, int** MatrixA, int** MatrixB );
void SubMatrixByMatrix( int Width, int Height, int** MatrixA, int** MatrixB );
void TranspositionMatrix( int Width, int Height, int** Matrix );
void InsertInMatrix( int Width, int Height, int** Matrix );