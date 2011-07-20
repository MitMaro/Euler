# Problem 14
# By: Tim Oram

cache = {}

def collatz(number):
	global cache
	if number in cache:
		return cache[number]
	if number == 1:
		return 1

	if number&1:
		cache[number] = 1 + collatz(3*number + 1)
	else:
		cache[number] = 1 + collatz(number/2)

	return cache[number]

greatest = 0
greatest_i = 1

# odd numbers only
for i in xrange(1, 1000000):
	t = collatz(i)
	if (t > greatest):
		greatest = t
		greatest_i = i

print "Answer:", greatest_i

