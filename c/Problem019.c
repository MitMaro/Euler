// Problem 19
// By: Tim Oram

#include <stdio.h>

int main (void) {
	
	int month = 1, year = 1901, day = 1, weekday = 3;
	
	int months[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	
	int count = 0;
	
	while (day != 31 || month != 12 || year != 2000) {
		
		day++;
		weekday++;
		
		// check for leap year
		if (month == 2 && day > 28) {
			if ((year%4) == 0) {
				weekday++;
				day++;
			}
		}
		
		if (day > months[month]) {
			day = 1;
			month++;
			if (month > 12) {
				month = 1;
				year++;
			}
		}
		
		if (weekday > 7) {
			weekday %= 7;
			if (weekday == 1 && day == 1) {
				count++;
			}
		}
	}
	
	printf("Answer: %d\n", count);
	return 0;
}



