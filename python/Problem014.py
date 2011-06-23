# Problem 14
# By: Tim Oram
#
# Runtime: 2.222s

cache = {}

def collatz(number):
	global cache
	if number in cache:
		return cache[number]
	if number == 1:
		return 1

	if (number%2) == 0:
		cache[number] = 1 + collatz(number/2)
	else:
		cache[number] = 1 + collatz(3*number + 1)

	return cache[number]

greatest = 0
greatest_i = 1

for i in xrange(1, 1000001):
	t = collatz(i)
	if (t > greatest):
		greatest = t
		greatest_i = i

print greatest_i

