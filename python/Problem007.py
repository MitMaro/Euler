# Problem 7
# By: Tim Oram

import sys

factors = []

i = 1

while True:
	i += 1
	isPrime = True
	for j in factors:
		if ((i % j) == 0):
			isPrime = False
			break
	if isPrime:
		factors.append(i)
	
	if len(factors) == 10001:
		break

print "Answer:", factors[-1]
