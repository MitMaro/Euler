// Problem 12
// By: Tim Oram

#include <stdio.h>
#include <stdlib.h>


typedef struct cache_entry {
	int total;
	int value;
	int prime;
	int count;
	struct cache_entry* next;
} cache_item;

cache_item *insert_cache_item (cache_item *cache_head, cache_item *cache_node) {
	
	// empty list
	if (cache_head == NULL) {
		return cache_node;
	}
	
	// cache_node is first
	if (cache_head->prime > cache_node->prime) {
		cache_node->next = cache_head;
		cache_head->next = NULL;
		return cache_node;
	}
	
	// look for node greater than the cache_node
	cache_item *prev = cache_head;
	cache_item *pos = cache_head->next;
	while (pos != NULL && pos->prime < cache_node->prime) {
		prev = pos;
		pos = pos->next;
	}
	
	// insert cache_node
	prev->next = cache_node;
	cache_node->next = pos;
	
	return cache_head;
}

cache_item *find_cache_item (cache_item *cache_head, int prime) {
	
	while (cache_head != NULL) {
		if (cache_head->prime == prime) {
			return cache_head;
		} else if (cache_head->prime > prime) {
			return NULL;
		}
		cache_head = cache_head->next;
	}
	
	return NULL;
}

cache_item *create_cache_item (int prime, int total, int value, int count) {
	cache_item *item = (cache_item*)malloc(sizeof (cache_item));
	item->total = total;
	item->prime = prime;
	item->value = value;
	item->count = count;
	return item;
}

cache_item *get_prime_factor_count (cache_item *cache_head, int number) {
	
	int static const primes[] = {2,3,5,7,11,13,17,19};
	
	int i, number_tmp;
	
	int total, value, count;
	
	cache_item *item;
	
	for (i = 0; i < 8; ++i) {
		if ((number%primes[i]) == 0) {
			number_tmp = number/primes[i];
			
			if ((item = find_cache_item(cache_head, number_tmp)) == NULL) {
				item = get_prime_factor_count(cache_head, number_tmp);
			}
			
			if (item->value == primes[i]) {
				count = item->count + 1;
				value = item->value;
				total = item->total;
			} else if (item->value != -1) {
				count = 1;
				value = primes[i];
				total = item->total * (item->count + 1);
			} else {
				count = 0;
				value = -1;
				total = 0;
			}
			return create_cache_item(number, total, value, count);
		}
	}
	
	// primes miss
	return create_cache_item(number, 0, -1, 0);
	
}

int main (void) {
	
	cache_item *cache_head;
	
	cache_item *item;
	
	item = create_cache_item(2,1,2,1);
	cache_head = insert_cache_item(cache_head, item);
	item = create_cache_item(3,1,3,1);
	cache_head = insert_cache_item(cache_head, item);
	item = create_cache_item(5,1,5,1);
	cache_head = insert_cache_item(cache_head, item);
	item = create_cache_item(7,1,7,1);
	cache_head = insert_cache_item(cache_head, item);
	item = create_cache_item(11,1,11,1);
	cache_head = insert_cache_item(cache_head, item);
	item = create_cache_item(13,1,13,1);
	cache_head = insert_cache_item(cache_head, item);
	item = create_cache_item(17,1,17,1);
	cache_head = insert_cache_item(cache_head, item);
	item = create_cache_item(19,1,19,1);
	cache_head = insert_cache_item(cache_head, item);
	
	item = cache_head;
	
	int inc = 3;
	int number = 3;
	int total;
	
	do {
		number += (inc++);
		item = get_prime_factor_count(cache_head, number);
		total = item->total * (item->count + 1);
	} while (total <= 500);
	
	printf("%d\n", number);
	return 0;
}
