#include "geometrics.h"
#include <stdio.h>
int main()
{
   Figure *Squer = CreateFigure();
   CreateSquare( Squer );
   PointOutput( Squer );
   printf("Area: %f\n", CalcArea( Squer ));
   FreeFigure( Squer );
}

