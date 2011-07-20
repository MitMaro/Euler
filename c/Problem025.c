// Problem 25
// By: Tim Oram

#include <stdio.h>

int main (void) {
	
	int i = 2;
	
	float a = 1.0, b = 1.0, tmp;
	
	int num_digits = 1;
	
	while (num_digits < 1000) {
		
		tmp = b;
		b = tmp + a;
		a = tmp;
		i++;
		if (b >= 10) {
			b /= 10;
			a /= 10;
			num_digits++;
		}
	}
	printf("Answer: %d\n", i);
	return 0;
}



