# Problem 5
# By: Tim Oram
#
# Runtime: 0.018s

import math

i = 20;

while True:
	done = True
	for j in xrange(1,21):
		if (i % j) != 0:
			done = False
			break
	if done:
		break 
	else:
		# if a prime then the only option is to multiply by the prime
		if j in [1,2,3,5,7,11,13,17,19]:
			i *= j
		elif j in [4, 8, 12, 16, 18, 20]:
			i *= 2
		elif j in [9, 15]:
			i *= 3
		

print "Answer:", i
