# Problem 21
# By: Tim Oram

sums = [0] * 10000

total = 0

for i in range(1, 10001):
	sum = 1
	j = 2
	while j*j <= i:
		if (i%j) == 0:
			sum += j + int(i/j)
		j += 1
	
	sums[i-1] = sum

for i in range(0, 10000):
	for j in range(0, 10000):
		if (j == i):
			continue
		
		if sums[i] == j + 1 and sums[j] == i + 1:
			total += i + 1
			
		
	
print "Answer:", total