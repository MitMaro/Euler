# Problem 20
# By: Tim Oram
#
# Runtime: 0.019s

import math

value = math.factorial(100)
total = 0

for i in str(value):
	total += int(i)
	
print total
