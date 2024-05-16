#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Author: Bronzal, Lance Stephen L. | BUCS BSCS 1A */

int main(int argc, char *argv[]) {
	
	//Rectangle
	float l, w;
	printf("Rectangle\nPlease input the length and width of rectangle: ");
	scanf("%f%f", &l, &w);
	float rec_p = (l + w) * 2; 	//rectangle's perimeter
	float rec_a = l * w; 		//rectangle's area
	printf("Rectangle's Perimeter: %g\n", rec_p);
	printf("Rectangle's Area: %g\n\n", rec_a);
	
	//Triangle
	float a, b, c;
	printf("Triangle\nPlease input the three sides of the triangle: ");
	scanf("%f%f%f", &a, &b, &c);
	float tri_p = a + b + c; 		//triangle's perimeter
	float s = tri_p / 2;
	float radicand = s * (s-a) * (s-b) * (s-c);
	float tri_a = sqrt(radicand); 	//triangles's area
	printf("Triangle's Perimeter: %g\n", tri_p);
	printf("Triangle's Area: %g\n\n", tri_a);
	
	//Circle
	float r;
	const float pi = 3.14;
	printf("Circle\nPlease input the radius of the circle: ");
	scanf("%f", &r);
	float cir_c = 2 * pi * r; //circle's circumference
	float cir_a = pi * (r*r); //circle's area
	printf("Circle's Circumference: %g\n", cir_c);
	printf("Circle's Area: %g\n", cir_a);
	
	
	return 0;
}
