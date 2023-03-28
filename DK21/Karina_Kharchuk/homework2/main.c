#include <stdio.h>
#include "triangle.h"

int main (int argc, const char *argv[])
{
        printf("ab і ас є катетами, а bc - гіпотенуза\n");

        Point *a = create_point(1, 1);

        Point *b = create_point(1, 5);

        Line *ab = createLineByPoints(a, b);
        printf("length ab: %f\n", length_line(ab));
        print_line(ab);

        destroy_point(a);
        destroy_point(b);

        Line *bc = create_line(1, 5, 5, 1);

        printf("length bc: %f\n", length_line(bc));
        print_line(bc);

        Line *ca = create_line(5, 1, 1, 1);
        printf("length ca: %f\n", length_line(ca));
        print_line(ca);

        int val = validation(ab, ca, bc);
        
        if(val == 0)
        {
                printf("747\n");
                return 0;
        }

        printf("площа трикутника: %f\n", (length_line(ab)*length_line(ca))/2);

        for (int i = 1; i <= length_line(ab); ++i)
        {
                for (int j = 1; j <= i; ++j)
                {
                        printf("* ");
                }
                printf("\n");
        }

        destroy_line(ab);
        destroy_line(bc);
        destroy_line(ca);
        return 0;
}
