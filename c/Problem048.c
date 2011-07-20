// Problem 48
// By: Tim Oram

#include <stdio.h>

int main (void) {
	
	int i, j;
	
	unsigned long total = 0;
	unsigned long sum;
	
	for (i = 1; i < 1001; ++i) {
		sum = 1;
		for (j = 0; j < i; ++j) {
			sum *= i;
			
			// if sum hits 11 digits subtract the 11th
			if (sum > 10000000000) {
				sum -= (int)(sum/10000000000) * 10000000000;
			}
		}
		
		total += sum;
		// if total hits 11 digits subtract the 11th
		if (total > 10000000000) {
			total -= (int)(total/10000000000) * 10000000000;
		}
	}
	printf("Answer: %ld\n", total);
	return 0;
}



