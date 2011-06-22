# Problem 10
# By: Tim Oram
#
# Runtime: 44.426s


import math

num = 2000000

numbers = [True] * num

p = 2

numbers[0] = False
numbers[1] = False

while p*p < num:
	for i in xrange(p+1, len(numbers)):
		if numbers[i] and (i%p) == 0:
			numbers[i] = False
	i = p
	while True:
		i += 1
		if numbers[i]:
			p = i
			break

t = 0
for i in xrange(2,len(numbers)):
	if numbers[i]:
		t += i
print t  
