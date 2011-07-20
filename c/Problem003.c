// Problem 2
// By: Tim Oram

#include <stdio.h>

int isPrime(unsigned long n) {
	
	int i;
	
	if ((n%2) == 0) {
		return 0;
	}
	
	for (i = 3; i*i < n; i +=2) {
		if ((n%i) == 0) {
			return 0;
		}
	}
	
	return 1;
	
}

int main(void) {
	
	const unsigned long number = 600851475143;
	
	unsigned long i, j;
	int is_prime = 0;
	
	unsigned long highest = 1;
	unsigned long number_of_primes = 2;
	
	for (i = 3; i*i <= number; i += 2) {
		if ((number%i) == 0 && isPrime(i) == 1) {
			highest = i;
		}
	}
	
	printf("Answer: %lu\n", highest);
	return 0;
}

