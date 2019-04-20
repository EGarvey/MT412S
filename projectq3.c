/* 
 * Evaluates the integral of x^2*exp(-x^2) using Simpson's Rule with 20,000 steps. 
 * Then solves the equation of integral of x^2*exp(-x^2) from 0 to y = 0.1 for y, using bracketing and bisection. 
 */

#include <math.h>
#include <stdio.h>

double f(double x);

double simpsons(double x, double y);

int main(void) {

	double a, b, x, lower, higher, middle, simp, simp_old, value, value2;
	
	a = 0;
	b= 0;
		
	simp = simpsons(a,b);
	
	/*
	 * Keep applying Simpson's rule, incrementing b by 0.1 until the value of the integral is constant
	 */	
	do {	
	
		simp_old = simp;
		b += 0.1;
		simp = simpsons(a,b);
		
	} while (fabs(simp - simp_old) > 0.000001); 	
	
	
		
	printf("The value of the integral is: %lf.\n", simp); 
	
	
	lower = 0;
	higher = 99; /* b has to be between 0 and 100 */
	
	
	/*
	 * Use bracketing and bisection to first solve for the root of the equation, then uses the value of this root for y
	 */
	while (higher - lower > 0.000001) {
		middle = (lower + higher)/2.0;
		value = simpsons(0,middle)-0.1;
			    
		if (value >= 0.0) {

			higher = middle;
			
		}
		if (value <= 0.0) {
			
			lower = middle;
		}
	}

	printf("The value for y is: %lf.\n", middle); /* The value for y is equal to the value for middle as this is the root of the equation, where higher and lower are the same */
	
	value2 = simpsons(0,middle); /* Check to see if the value of the integral from 0 to y is 0.1 */
	
	printf("The value of the integral from 0 to y is %lf\n", value2);
			
	return 0;
}
double simpsons(double a, double b){
	
	/*
	* Uses Simpson's rule to solve integral of the function f
	 */

	int i, steps;
	double  h, x, lower, higher, middle, simp, value;
	
	steps = 20000;
	h = (b - a)/steps;
	simp = -f(a);
	x = a;
	for (i = 0; i < steps; i += 2) {
		simp += 2.0*f(x)+4.0*f(x+h);
		x += 2*h;
	}
	simp += f(b);
	simp *= h/3.0;
	return simp;
}
	
double f(double x) {
	
	return x*x*exp(-x*x);
}


