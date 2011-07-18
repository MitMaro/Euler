# Problem 17
# By: Tim Oram
#
# Runtime: 0.019

import math

number_map = {
	1: 3, 2: 3, 3: 5, 4: 4, 5: 4, 6: 3, 7: 5, 8: 5, 9: 4,
	10: 3, 11: 6, 12: 6, 13: 8, 14: 8, 15: 7, 16: 7, 17: 9, 18: 8, 19: 8,
	20: 6, 30: 6, 40: 5, 50: 5, 60: 5, 70: 7, 80: 6, 90: 6
}

total = 11 # One Thousand

for i in range(1, 1000):
	
	j = i
	d = int(math.floor(j/100));
	if (d >= 1):
		total += number_map[d] + 7 # 7 = hundred
		j = j - (d*100)
		
		if (j == 0): # even hundred
			continue
		else:
			total += 3 # and
	
	if j in number_map:
		total += number_map[j]
	else:
		d = int(math.floor(j/10) * 10)
		total += number_map[d]
		j = j - d
		total += number_map[j]

print "Answer:", total
