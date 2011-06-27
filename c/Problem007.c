// Problem 7
// By: Tim Oram
//
// Runtime: 0.023s

#include <stdio.h>

int main (void) {

	long i, j;
	int count = 1;
	int is_prime;
 
	for (i = 3;; i +=2) {
		is_prime = 1;
		if ((i%2) == 0) {
			is_prime = 0;
		}
		if (is_prime == 1) {
			for (j = 3; j*j <= i; j += 2) {
				if ((i%j) == 0) {
					is_prime = 0;
					break;
				}
			}
		}
		if (is_prime == 1) {
			count++;
			if (count == 10001) {
				break;
			}
		}
		
	}

	printf("Answer: %ld\n", i);
}
