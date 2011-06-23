# Problem 6
# By: Tim Oram
#
# Runtime: 0.019s

import math

a = 0
b = 0

for i in xrange(1, 101):
	a += math.pow(i,2)
	b += i

print int(math.pow(b,2) - a)
