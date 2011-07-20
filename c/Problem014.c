// Problem 14
// By: Tim Oram

#include <stdio.h>
#include <stdlib.h>

#define HASH_PRIME 238879

typedef struct cache_entry {
	unsigned int index;
	unsigned long number;
	struct cache_entry* next;
} cache_item;

cache_item *find_cache_item (cache_item *cache_head, unsigned long number) {
	
	while (cache_head != NULL) {
		if (cache_head->index == number) {
			return cache_head;
		}
		cache_head = cache_head->next;
	}
	
	return NULL;
}

cache_item *insert_cache_item (cache_item *cache_head, cache_item *cache_node) {
	
	// empty list
	if (cache_head == NULL) {
		return cache_node;
	}
	
	cache_node->next = cache_head->next;
	cache_head->next = cache_node;
	return cache_head;

}

cache_item *create_cache_item (int index, unsigned long number) {
	cache_item *item = (cache_item*)malloc(sizeof (cache_item));
	item->index = index;
	item->number = number;
	return item;
}

cache_item *collatz (cache_item **cache_bucket, unsigned long number) {
	
	cache_item *item;
	
	cache_item *cache_head = cache_bucket[number%HASH_PRIME];
	
	if ((item = find_cache_item(cache_head, number)) != NULL) {
		return item;
	}
	
	if (number&1) {
		item = collatz(cache_bucket, 3*number + 1);
	} else {
		item = collatz(cache_bucket, number/2);
	}
	
	item = create_cache_item(number, 1 + item->number);

	cache_bucket[number%HASH_PRIME] = insert_cache_item(cache_head, item);
	
	return item;
}

int main (void) {
	
	cache_item *item;
	
	cache_item *cache[HASH_PRIME+1] = {NULL};
	
	cache[1%HASH_PRIME] = create_cache_item(1, 1);

	int i, high_index;
	
	unsigned int high_number = 1;
	
	for (i = 1; i < 1000000; ++i) {
		
		item = collatz(cache, i);
		
		if (item->number > high_number) {
			high_number = item->number;
			high_index = i;
		}
	}
	
	printf("Answer: %d\n", high_index);
	return 0;
}