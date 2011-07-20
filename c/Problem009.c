// Problem 9
// By: Tim Oram

#include <stdio.h>

int main (void) {

	int i, j, k;
	for (i = 1; i <= 997; ++i) {
		for (j = i+1; j <= 999; ++j) {
			for (k = j+1; k <= 998; ++k) {
				if (i+j+k == 1000 && i*i + j*j == k*k) {
					printf("Answer: %d\n", i*j*k);
					return 0;
				}
			}
		}
	}
	return 1;
}
