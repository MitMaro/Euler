// Problem 16
// By: Tim Oram

#include <stdio.h>
#include <stdlib.h>

typedef struct struct_digit {
	unsigned int number;
	struct struct_digit* next;
} digit;

int main (void) {
	digit *head = (digit*)malloc(sizeof (digit));
	
	digit *pos;
	
	head->number = 1;
	
	int i;

	int total = 0;
	
	int carry = 0;
	
	for (i = 0; i < 1000; ++i) {
		pos = head;
		do {
			pos->number = pos->number * 2 + carry;
			carry = 0;
			if (pos->number > 9) {
				if (pos->next == NULL) {
					pos->next = (digit*)malloc(sizeof (digit));
					pos->next->number = 1;
					pos->number -= 10;
					break;
				} else {
					pos->number -= 10;
					carry = 1;
				}
			}
			pos = pos->next;
		} while (pos != NULL);
	}
	
	pos = head;
	
	do {
		total += pos->number;
		pos = pos->next;
	} while (pos != NULL);
	
	printf("Answer: %d\n", total);
	return 0;
}