// Problem 6
// By: Tim Oram

#include <stdio.h>

int main (void) {

	long i;
	long sum1 = 0, sum2 = 0;
 
	for (i = 1; i <= 100; ++i) {
		sum1 += i;
		sum2 += i*i;
	}

	printf("Answer: %ld\n", sum1*sum1-sum2);
}
