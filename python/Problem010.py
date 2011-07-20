# Problem 10
# By: Tim Oram


import math

num = 2000000

numbers = [True] * num

p = 3

numbers[0] = False
numbers[1] = False

for i in xrange(2, 2000000, 2):
	numbers[i] = False
	
while p*p <= num:
	for i in xrange(p+2, 2000000, 2):
		if numbers[i] and (i%p) == 0:
			numbers[i] = False
	while True:
		p += 2
		if numbers[p]:
			break

t = 2
for i in xrange(3, 2000000, 2):
	if numbers[i]:
		t += i
print "Answer:", t
