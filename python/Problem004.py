# Problem 4
# By: Tim Oram
#
# Runtime: 0.580s

import math

highest_i = 99
highest_j = 99
highest = 0
for i in xrange(100, 1000):
	for j in xrange(100, 1000):
		s = str(i*j)
		if len(s) == 6 and s[0:3] == s[:2:-1] and highest < int(s):
			highest = int(s)
			highest_i = i
			highest_j = j

print "Answer:", highest



