// Problem 28
// By: Tim Oram

#include <stdio.h>

int main (void) {
	
	int i = 0;
	
	unsigned int j = 1;
	
	unsigned int sum = 1;
	
	while (i+1 < 1001) {
		i+= 2;
		j += i;
		sum += j;
		j += i;
		sum += j;
		j += i;
		sum += j;
		j += i;
		sum += j;
	}
	
	printf("Answer: %d\n", sum);
	return 0;
}



