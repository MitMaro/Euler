// Problem 29
// By: Tim Oram

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool search(short needle[98], short haystack[][98], int l) {
	
	int i, j;
	short primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	bool found;
	for (i = 0; i < l; i++) {
		
		found = false;
		for (j = 0; j < 25; j++) {
			if (haystack[i][primes[j]] != needle[primes[j]]) {
				found = true;
				break;
			}
		}
		if (!found) {
			return true;
		}
	}
	
	return false;
}


int main (void) {
	
	short nums[99*99][98];
	short num[98];
	
	short primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	
	memset(nums, 0, sizeof(nums));
	
	int insert_index = 0;
	
	int i;
	int j;
	int k;
	int a;
	
	for (i = 2; i < 101; ++i) {
		
		// reset array
		memset(num, 0, sizeof(num));
		
		// factor the base
		a = i;
		k = 0;
		while (k < 25 && a != 1) {
			if ((a % primes[k]) == 0) {
				num[primes[k]]++;
				a = a / primes[k];
			} else {
				k++;
			}
		}
		
		for (j = 2; j < 101; ++j) {
			memcpy(nums[insert_index], num, sizeof num);
			
			// (a^b * c^d)^e is (a^be * c^de)
			for (k = 0; k < 25; k++) {
				nums[insert_index][primes[k]] *= j;
			}
			
			if (!search(nums[insert_index], nums, insert_index - 1)) {
				insert_index++;
			}
			
		}
	}
	
	printf("Answer: %d\n", insert_index);
	return 0;
}
