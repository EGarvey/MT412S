/* Use the Goldbach conjecture: 'every even integer greater than 2 can be expressed as the sum of two primes' to read in an even
number n and write it as the sum of two primes. */

#include <stdio.h>

int Primetest(int x);
int main(void) {
	int n, prime1, prime2, check;
	int j;
	printf("Please enter an even number that is greater than two: ");
	if(scanf("%d", &n) != 1){
		printf("Couldn’t read number.\n");
		return 1;
	}
	
	
	if(n<=2 || n%2 != 0){
		printf("The number has to be even or greater than 2.\n");
		return 1;
	}
	
	prime1 =1; prime2=1;
		
	for (j=2; j<n; j++){
		check = Primetest(j); /* First check if j is prime, or if not prime finds a number that divides j */
		prime1 = Primetest(check); /* Makes sure the number that divides j is prime, if not it returns a prime that divides it */
		prime2 = n-prime1;
		check = Primetest(prime2); /* Checks to see if prime2 is actually prime */

		if(check == prime2){ /* If prime2 is prime, it will equal check and we have our two primes */
	
			printf("Number expressed as the sum of two primes: %d + %d = %d\n", prime1, prime2,n );
			break;	
		}
	}	

	return 0;
}

int Primetest(int x) {
		
	int i;
	/* Checks if number x is prime by trial division. Returns a number it is divisible by if it's not prime, returns the number if it is prime*/
	for(i=2; i<=x; i++){
		if(x%i==0){
			break;
		}
	}
	
	return i;
}
	
	

