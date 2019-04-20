/* 
 * Reads in a real number x and prints out x^2, 1/x, sqrt(x), sin(x) and log(x).
 */

#include <stdio.h>
#include <math.h>

int main(void) {
	int i;
	double x, function[5];
	
	printf("Please enter a real number: ");
	
	if (scanf("%lf", &x) != 1) {
		fprintf(stderr, "Couldn’t read number.\n");
		return 1;
	}
		 
	function[0] = x*x;
	function[1] = 1/x;
	function[2] = sqrt(x);
	function[3] = sin(x);
	function[4] = log(x);
		
	printf("The functions: %g^2, 1/%g, sqrt(%g), sin(%g), log(%g) are equal to (respectively): \n", x, x, x, x, x );
	
	/* Runs through the 5 functions and prints out the result. If the answer is undefined it prints an error */
	for(i=0; i<5; i++){ 
		
		if(i==1 && x==0){
			printf("Error computing 1/x, answer is undefined as x=0\n");
			
		}else if (i==4 && x==0){
			printf("Error computing log(x), answer is undefined as x=0\n");
		}else if (i==2 && x<0){
			printf("Error computing sqrt(x), answer is undefined as x<0\n");
		}else if(i==4 && x<0){
			printf("Error computing log(x), answer is undefined as x<0\n");
		}else{
			printf("%g\n", function[i]);
		}		
	}
	
	return 0;
}
