// Problem 23
// By: Tim Oram

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct struct_number {
	unsigned int number;
	struct struct_number* next;
} abundant_number;

abundant_number *add_abundant_number (abundant_number *head, int number) {
	
	abundant_number *node = (abundant_number*)malloc(sizeof (abundant_number));
	node->number = number;
	node->next = head;
	return node;
}


int main (void) {
	
	abundant_number *head = add_abundant_number(NULL, 12);
	abundant_number *num1;
	abundant_number *num2;
	
	bool sums[28123] = {false};
	
	int i, j, tmp;
	
	int sum;
	
	// find abundant numbers
	for (i = 13; i <= 28124; ++i) {
		sum = 1;
		for (j = 2; j*j <= i; ++j) {
			if ((i%j) == 0) {
				sum += j;
				tmp = (i/j);
				if (tmp != j) {
					sum += tmp;
				}
				
			}
		}
		if (sum > i) {
			head = add_abundant_number(head, i);
		}
	}
	
	num1 = head;
	
	// this could be improved by reversing the order of the linked list
	do {
		num2 = num1;
		do {
			if ((num1->number + num2->number) < 28123) {
				sums[num1->number + num2->number] = true;
			}
			num2 = num2->next;
		} while (num2 != NULL);
		num1 = num1->next;
	} while (num1 != NULL);
	
	sum = 0;
	for (i = 0; i < 28123; ++i) {
		if (!sums[i]) {
			//printf("%d %d\n", i, sums[i]);
			sum += i;
		}
	}
	
	printf("Answer: %d\n", sum);
	return 0;
}



