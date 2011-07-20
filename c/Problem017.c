// Problem 18
// By: Tim Oram

#include <stdio.h>

int main (void) {
	
	
	int number_map[100] = {0};
	number_map[1] = 3;
	number_map[2] = 3;
	number_map[3] = 5;
	number_map[4] = 4;
	number_map[5] = 4;
	number_map[6] = 3;
	number_map[7] = 5;
	number_map[8] = 5;
	number_map[9] = 4;
	number_map[10] = 3;
	number_map[11] = 6;
	number_map[12] = 6;
	number_map[13] = 8;
	number_map[14] = 8;
	number_map[15] = 7;
	number_map[16] = 7;
	number_map[17] = 9;
	number_map[18] = 8;
	number_map[19] = 8;
	number_map[20] = 6;
	number_map[30] = 6;
	number_map[40] = 5;
	number_map[50] = 5;
	number_map[60] = 5;
	number_map[70] = 7;
	number_map[80] = 6;
	number_map[90] = 6;
	
	int i, j, d;
	
	int total = 11; // One Thousand
	
	for (i = 1; i < 1000; ++i) {
		j = i;
		
		d = (int)(j/100);
		
		if (d >= 1) {
			total += number_map[d] + 7;
			
			j -= (d*100);
			
			if (j == 0) { // even hundred
				continue;
			} else {
				total += 3; // and
			}
		}
		
		if (number_map[j] != 0) {
			total += number_map[j];
		} else {
			d = ((int)(j/10)) * 10;
			total += number_map[d];
			j -= d;
			total += number_map[j];
		}
	}
 
	printf("Answer: %d\n", total);
	return 0;
}
