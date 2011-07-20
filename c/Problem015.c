// Problem 15
// By: Tim Oram

#include <stdio.h>
#include <math.h>

int main (void) {
	
	unsigned long layer[41] = {0};
	unsigned long layer_tmp[41] = {0};
	
	layer[20] = 1;
	layer_tmp[20] = 1;
	
	int i, j;
	
	// bottom half of triangle
	for (i = 1; i < 20; ++i) {
		
		for (j = 20 - i; j < 21 + i; j += 2) {
			layer_tmp[j] = layer[j-1] + layer[j+1];
		}
		
		// copy from tmp to actual
		for (j = 0; j < 41; ++j) {
			layer[j] = layer_tmp[j];
		}
	}
	
	// center layer
	layer_tmp[0] = 1;
	layer_tmp[40] = 1;
	for (j = 2; j < 39; j += 2) {
		layer_tmp[j] = layer[j-1] + layer[j+1];
	}
	// copy from tmp to actual
	for (j = 0; j < 41; ++j) {
		layer[j] = layer_tmp[j];
	}
	
	// top half of triangle
	for (i = 19; i >= 0; --i) {
		
		for (j = 20 - i; j < 21 + i; j += 2) {
			layer_tmp[j] = layer[j-1] + layer[j+1];
		}
		
		// copy from tmp to actual
		for (j = 0; j < 41; ++j) {
			layer[j] = layer_tmp[j];
		}
	}
	
	printf("Answer: %ld\n", layer[20]);
	return 0;
}



