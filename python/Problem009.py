# Problem 9
# By: Tim Oram
#
# Runtime: 4.560s 

import math
import sys

for i in xrange(2, 1001):
	for j in xrange(i+1,1001 - i):
		for k in xrange(j+1,1001 - i - j):
			if (i+j+k) != 1000:
				continue
			
			if (math.pow(i,2) + math.pow(j,2)) == math.pow(k,2):
				print "Answer:", i * j * k
				sys.exit()
