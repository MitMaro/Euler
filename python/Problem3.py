# Problem 3
# 
# By: Tim Oram
#
# Runtime: 0.115s

import math
import sys

factors = []
number = 600851475143
sqrtnumber = int(math.floor(math.sqrt(number))) + 1

for i in xrange(2, sqrtnumber):
	# if number divides i
	if ((number % i) == 0):
		isPrime = True
		for j in factors:
			if ((i % j) == 0):
				isPrime = False
				break
		if isPrime:
			factors.append(i)

factors.sort()

print factors[-1]



