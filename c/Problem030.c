// Problem 30
// By: Tim Oram

#include <stdio.h>
#include <math.h>

int main (void) {
	
	int i;
	
	int number = 10;
	int total = 0;
	int sub_total = 0;
	
	// max sum of 6 digits = 354294 which is no where near 999999
	while (number < 999999) {
		
		sub_total = 0;
		
		for (i = 0; pow(10, i) < number; ++i) {
			sub_total += pow((int)(number / pow(10, i)) % 10, 5);
		}
		
		if (sub_total == number) {
			total += sub_total;
		}
		number++;
	}
	
	printf("Answer: %d\n", total);
	return 0;
}
