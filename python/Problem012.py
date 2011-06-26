# Problem 12
# By: Tim Oram
#
# Runtime: 0.227s

def getPrimeFactors(number):
	global primes
	global cache
	
	for i in primes:
		if (number%i) == 0:
			n = number/i
			
			# cache miss, build it
			if n not in cache:
				getPrimeFactors(n) 
			
			t, v, c = cache[n]
			
			# if previous prime is the same as this one
			if v == i:
				c += 1
			# different prime, update the total and value
			elif v != -1: # -1 is in invalid number (outside prime range)
				t = t * (c+1)
				v = i
				c = 1
			
			# cache value
			cache[number] = [t,v,c]
			return
			
	# the number has a prime multiple that is larger than the 8th prime
	cache[number] = [-1,0,0]

# since the product of the first 9 primes has 512 multiples it can be used
# as an upper limit. Any product that is less than this will contain only the
# first 8 primes.
primes = [2,3,5,7,11,13,17,19]

# prefill cache with 
cache= {
	2:[1,2,1],
	3:[1,3,1],
	5:[1,5,1],
	7:[1,7,1],
	11:[1,11,1],
	13:[1,13,1],
	17:[1,17,1],
	19:[1,19,1]
}

# loop over triangle numbers
i = 3
n = 3
while True:
	n += i
	i += 1
	getPrimeFactors(n)
	t,v,c = cache[n]
	t  = t * (c+1)
	if t > 500:
		print n
		break


