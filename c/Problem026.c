// Problem 26
// By: Tim Oram

#include <stdio.h>
#include <stdlib.h>

typedef struct struct_digit {
	int number;
	int remainder;
	struct struct_digit *next;
} digit;


// Handle the digits
digit *add_digit(digit* prev, int number, int remainder) {
	digit *node = (digit*)malloc(sizeof (digit));
	node->number = number;
	node->remainder = remainder;
	node->next = NULL;
	if (prev != NULL) {
		prev->next = node;
	}
	
	return node;
}

void clean_digit(digit* head) {
	digit *next;
	while(head->next != NULL) {
		next = head->next;
		free(head);
		head = next;
	}
	free(head);
	head = NULL;
}


int count_cycle(digit* head, int n, int r) {
	digit *d = head;
	int count = -1;
	
	
	while (d != NULL) {
		if (d->number == n && d->remainder == r) {
			count = 0;
		}
		if (count >= 0) {
			count++;
		}
		
		d = d->next;
	}
	
	return count;
	
}

int find_cycle(int d) {
	digit *digits;
	digit *digit_head;
	
	digits = digit_head = add_digit(NULL, 0, 0);
	digits->number = 0;
	
	int count;
	int n = 10;
	
	int q;
	int r = 1;
	
	while (r > 0) {
		q = n/d;
		r = n - q * d;
		
		if ((count = count_cycle(digit_head, q, r)) > 0) {
			clean_digit(digit_head);
			return count;
		}
		
		digits = add_digit(digits, q, r);
		
		n = digits->remainder * 10;
	}
	
	clean_digit(digit_head);
	
	// not a cycle
	return -1;
	
}

int main (void) {
	
	int max = 0;
	int cycle_count;
	int max_cycle_number = 0;
	int d;


	for (d = 2; d < 1000; ++d) {
		cycle_count = find_cycle(d);
		
		if (cycle_count > max) {
			max_cycle_number = d;
			max = cycle_count;
		}
	}
	
	printf("Highest Number: %d, Cycle Count: %d\n", max_cycle_number, max);
	return 0;
}



