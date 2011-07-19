// Problem 10
// By: Tim Oram
//
// Runtime: 1.791s

#include <stdio.h>

int main (void) {

	int primes[2000000] = {0};

	int i, j;
	
	unsigned long sum;

	// remove 2s
	for (i = 4; i <= 2000000; i += 2) {
		primes[i] = 1;
	}

	i = 3;

	while (i*i <= 2000000) {
		for (j = i+2; j < 2000000; j += 2) {
			if (!primes[j] && (j%i) == 0) {
				primes[j] = 1;
			}
		}
		
		do {
			i += 2;
		} while (primes[i]);
	}
	sum = 2;
	for (i = 3; i < 2000000; i += 2) {
		if (!primes[i]) {
			sum += i;
		}
	}

	printf("Answer: %ld\n", sum);
	return 0;
}
