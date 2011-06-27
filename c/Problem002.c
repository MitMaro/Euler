// Problem 2
// By: Tim Oram
//
// Runtime: 0.001s

#include <stdio.h>

int main(void) {
	
	int sum = 0;
	
	int a = 1;
	int b = 2;
	int t = 0;
	
	while (b < 4000000) {
		if ((b%2) == 0) {
			sum += b;
		}
		t = a;
		a = b;
		b = t + a;
	}
	
	printf("Answer: %d\n", sum);
	return 0;
}
