# Problem 16
# By: Tim Oram
#
# Runtime: 0.019s

import math

value = int(math.pow(2, 1000))
total = 0

for i in str(value):
	total += int(i)

print "Answer:", total
