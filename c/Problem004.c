// Problem 4
// By: Tim Oram
//
// Runtime: 0.005s

#include <stdio.h>

int main(void) {
	
	int i, j, p;
	
	int a,b,c,d,e,f; // temps for holding digits
	
	int highest = 0;
	
	for (i = 100; i < 1000; ++i) {
		for (j = 100; j < 1000; ++j) {
			p = i * j;
			
			if (p < highest) {
				continue;
			}
			
			if (p < 100000) { // p has 5 digits
				a = (int)(p/10000);
				b = (int)((p-(a*10000))/1000);
				c = (int)((p-(a*10000)-(b*1000))/100);
				d = (int)((p-(a*10000)-(b*1000)-(c*100))/10);
				e = (int)(p-(a*10000)-(b*1000)-(c*100)-(d*10));
				
				if (a == e && b == d) {
					highest = p;
				}
				
			} else { // p has 6 digits
				a = (int)(p/100000);
				b = (int)((p-(a*100000))/10000);
				c = (int)((p-(a*100000)-(b*10000))/1000);
				d = (int)((p-(a*100000)-(b*10000)-(c*1000))/100);
				e = (int)((p-(a*100000)-(b*10000)-(c*1000)-(d*100))/10);
				f = (int)(p-(a*100000)-(b*10000)-(c*1000)-(d*100)-(e*10));
				
				if (a == f && b == e && c == d) {
					highest = p;
				}
			}
		}
	}
	
	printf("Answer: %d\n", highest);
	return 0;
}
