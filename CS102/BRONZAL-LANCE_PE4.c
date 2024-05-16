#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A */

int main(int argc, char *argv[]) {
	
	float x1,y1,x2,y2,m,midpoint_x, midpoint_y, m_bisector, y_int;
	printf("Enter the x and y coordinates of the first point (P1): ");
	scanf("%f%f", &x1, &y1);
	printf("Enter the x and y coordinates of the second point (P2): ");
	scanf("%f%f", &x2, &y2);
	
	printf("\nThe coordinates of the points are P1(%g, %g) and P2(%g, %g).\n", x1,y1,x2,y2); //Outputs the two points right away.
	
	if (y2>y1){
		m = (y2 - y1) / (x2 - x1);
	}
	else{
		m = (y1 - y2) / (x1 - x2);
	}
	printf("The slope of the line segment between P1 and P2 is: %g\n", m);
	
	midpoint_x = (x1 + x2) / 2;
	midpoint_y = (y1 + y2) / 2;
	printf("The coordinates of the midpoint between P1 and P2 is (%g, %g)\n", midpoint_x, midpoint_y);
	
	m_bisector = -(1 / m);
	printf("The slope of the perpendicular bisector of the line segment between P1 and P2 is: %g\n", m_bisector);
	
	y_int = (midpoint_y - (m_bisector * midpoint_x));
	printf("The y-intercept of the perpendicular bisector is: %g\n", y_int);
	
	printf("The equation of the perpendicular bisector is: y = %gx + %g\n", m_bisector, y_int);
	
	return 0;
}
