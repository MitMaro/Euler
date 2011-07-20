# Problem 20
# By: Tim Oram

import math

value = math.factorial(100)
total = 0

for i in str(value):
	total += int(i)
	
print "Answer:", total
