// Problem 20
// By: Tim Oram

#include <stdio.h>
#include <stdlib.h>

typedef struct struct_digit {
	unsigned int number;
	struct struct_digit* next;
} digit;

void multiply (digit *node, int multiple, int carry) {
	
	node->number = node->number * multiple + carry;
	
	if (node->number > 9) {
		carry = (node->number - (node->number%10))/10;
		
		node->number = node->number%10;
		
		if (node->next == NULL) {
			node->next = (digit*)malloc(sizeof (digit));
			node->next->number = 0;
		}
		multiply(node->next, multiple, carry);
	} else if (node->next != NULL) {
		multiply(node->next, multiple, 0);
	}
}

int main (void) {
	digit *head = (digit*)malloc(sizeof (digit));
	
	digit *pos;
	
	head->number = 1;
	
	int i;
	int total = 0;

	for (i = 1; i < 101; ++i) {
		multiply(head, i, 0);
	}
	
	pos = head;
	
	do {
		total += pos->number;
		pos = pos->next;
	} while (pos != NULL);
	
	printf("Answer: %d\n", total);
	return 0;
}