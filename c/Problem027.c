// Problem 27
// By: Tim Oram

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


bool is_prime(unsigned int p) {
	
	unsigned int i;
	
	if ((p%2) == 0) {
		return false;
	}
	
	for (i = 3; i*i < p; i +=2) {
		if ((p%i) == 0) {
			return false;
		}
	}
	
	return true;
}

int main (void) {
	
	int n;
	int max_count;
	int max_product;
	int a;
	int b;
	
	for (a = -1000 + 1; a < 1000; a++) {
		for (b = -1000 + 1; b < 1000; b++) {
			
			n = 0;
			while(is_prime(abs(n*n + a*n + b))) {
				n++;
			}
			
			if (n > max_count) {
				max_count = n;
				max_product = a * b;
			}
		}
	}
	
	printf("Answer: %d\n", max_product);
	return 0;
}
