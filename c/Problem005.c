// Problem 5
// By: Tim Oram

#include <stdio.h>

int main(void) {
	
	int found = 0; // found flag
	
	int j;
	
	int i = 20;
	
	for(;;) {
		found = 1;
		for (j = 2; j < 21; ++j) {
			if ((i%j) != 0) {
				found = 0;
				break;
			}
		}
		
		if (found == 1) {
			break;
		}
		
		// if prime, multiply by prime
		if (j == 2 || j == 3 || j == 5 || j == 7 || j == 11 || j == 13 || j == 17 || j == 19) {
			i *= j;
		} else if (j == 4 || j == 8 || j == 12 || j == 16 || j == 18) {
			i *= 2;
		} else if (j == 9 || j == 15) {
			i *= 3;
		}
	}
	
	printf ("Answer: %d\n", i);
	return 0;
}
