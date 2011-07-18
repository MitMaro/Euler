# Problem 1
# By: Tim Oram
#
# Runtime: 0.019s

import math

t = 0
for i in xrange(3, 1000):
	if (i%3) == 0 or (i%5) == 0:
		t += i

print "Answer:", t
