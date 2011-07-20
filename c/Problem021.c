// Problem 21
// By: Tim Oram

#include <stdio.h>

int main (void) {
	
	int i, j;
	
	int sums[10000] = {0};
	
	int sum, total = 0;
	
	for (i = 1; i < 10001; ++i) {
		sum = 1;
		for (j = 2; j*j <= i; ++j) {
			if ((i%j) == 0) {
				sum += j + (int)(i/j);
			}
		}
		sums[i-1] = sum;
	}
	
	for (i = 0; i < 10000; ++i) {
		for (j = 0; j < 10000; ++j) {
			if (j == i) {
				continue;
			}
			
			if (sums[i] == j + 1 && sums[j] == i + 1) {
				total += i + 1;
			}
		}
	}
	
	printf("Answer: %d\n", total);
	return 0;
}

