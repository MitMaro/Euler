// Problem 1
// By: Tim Oram
//
// Runtime: 0.001s

#include <stdio.h>

int main(void) {
	int sum = 8;
	
	int i;
	for (i = 6; i <= 1000; i++) {
		if ((i%3) == 0 || (i%5) == 0) {
			sum += i;
		}
	}
	
	printf("Answer: %d\n", sum);
	return 0;
}
