#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"

Point *create_point(int x, int y)
{
        Point *result = (Point *)malloc(sizeof(Point));
        if(NULL != result)
        {
                result->x = x;
                result->y = y;
        }

 }

 void print_point(Point *aPoint)
 {
        if(NULL == aPoint)
        {
                printf("Invalid object");
                return;
        }

  printf("{%d, %d}", aPoint->x, aPoint->y);
 }

void destroy_point(Point *a) 
{
        if (NULL != a) 
        {
                free(a);
        }
}

Line *create_line(int ax, int ay, int bx, int by)
{
        Line *result = (Line *)malloc(sizeof(Line));

        if(NULL != result)
        {
                result->A = create_point(ax, ay);
                result->B = create_point(bx, by);
        }

        return result;
}

Line *createLineByPoints(Point *anA, Point *aB)
{
        if (NULL == anA || NULL == aB)
        {
                return NULL;
        }

        return create_line(anA->x, anA->y, aB->x, aB->y);
}
void print_line(Line *aLine)
{
        if(NULL == aLine)
        {
                return;
        }

        print_point(aLine->A);
        printf("-");
        print_point(aLine->B);
        printf("\n");
}
double length_line(Line *aLine)
{
        if(NULL == aLine)
        {
                return -1;
        }
        return sqrt((aLine->B->x - aLine->A->x) * (aLine->B->x - aLine->A->x) + (aLine->B->y - aLine->A->y) * (aLine->B->y - aLine->A->y));

}

void destroy_line(Line *aLine)
{
        if(NULL == aLine)
        {
                return;
        }

        destroy_point(aLine->A);
        destroy_point(aLine->B);

        free(aLine);
}
