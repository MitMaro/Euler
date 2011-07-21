# Problem 19
# By: Tim Oram

month = 1
year = 1901
day = 1
weekday = 3

months = [0,31,28,31,30,31,30,31,31,30,31,30,31]

count = 0

while day != 31 or month != 12 or year != 2000:
	day += 1
	weekday += 1
	
	if month == 2 and day > 28:
		if (year%4) == 0:
			weekday += 1
			day += 1
		
	
	if day > months[month]:
		day = 1
		month += 1
		if month > 12:
			month = 1
			year += 1
		
	
	if weekday > 7:
		weekday %= 7
		if weekday == 1 and day == 1:
			count += 1
			
		
	

print "Answer:", count
