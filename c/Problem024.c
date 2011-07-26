// Problem 24
// By: Tim Oram

#include <stdio.h>

#define ELEMENT_COUNT 10

void swap (int *c, int i, int j) {
	//printf("Swap(%d, %d)\n", i , i - 1);
	int tmp = c[i];
	c[i] = c[j];
	c[j] = tmp;
}

void print_array(int *a) {
	int i;
	for (i = 0; i < ELEMENT_COUNT; ++i) {
		printf("%d", a[i]);
	}
	printf("\n");
}

void permutate (int *numbers, int d) {
	static int count = 0;
	
	int i;
	
	// break out of function once a million is hit as there is no longer a 
	// need to continue
	if (count == 1000000) {
		return;
	}
	
	if (d == ELEMENT_COUNT - 1) {
		count++;
		if (count == 1000000) {
			printf("Answer: ");
			print_array(numbers);
		}
		return;
	}
	
	permutate(numbers, d+1);
	for (i = d + 1; i < ELEMENT_COUNT; i++) {
		swap(numbers, d, i);
		permutate(numbers, d+1);
	}

	for (i = ELEMENT_COUNT - 1; i > d; i--) {
		swap(numbers, d, i);
	}
}

int main (void) {
	
	int numbers[] = {0,1,2,3,4,5,6,7,8,9};
	
	permutate(numbers, 0);
	return 0;
}



