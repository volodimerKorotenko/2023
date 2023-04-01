#include <stdio.h>
#include "point.h"
#include "ellipse.h"

int main () {
int cx=0, cy=0, a=1, b=2; // a - довга вісь, b - коротка вісь
printf("Enter Center X: ");
scanf("%d", &cx);
printf("Enter Center Y: ");
scanf("%d", &cy);
printf("Enter Major Axis: ");
scanf("%d", &a);
printf("Enter Minor Axis: ");
scanf("%d", &b);
printf("\n");

Ellipse *ellipse = createEllipse(cx, cy, a, b);
printf("Ellipse: ");
printEllipse(ellipse);
printf("\n");
printf("Ellipse area: %f\n", getEllipseArea(ellipse));
destroyEllipse(ellipse);
printf("\n");

return 0;
}
