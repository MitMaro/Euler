# Problem 26
# By: Tim Oram

def count_cycle(digits, n, r):

	count = -1;
	
	for d in digits:
		if (d[0] == n and d[1] == r):
			count = 0;
			
		if (count >= 0):
			count += 1;
	
	return count;


def find_cycle(d):
	digits = [];
	
	n = 10;
	r = 1;
	
	while (r > 0):
		q = n/d;
		r = n - q * d;
		
		count = count_cycle(digits, q, r)
		if (count > 0):
			return count;
		
		digits.append((q,r))
		n = r * 10;
	
	# no cycle found
	return -1;
	
max_cycle = 0
max_number = 0

for d in range(2, 1000):
	cycle_count = find_cycle(d)
	
	if (cycle_count > max_cycle):
		max_number = d
		max_cycle = cycle_count
	

print "Highest Number:", max_number, "Cycle Count:", max_cycle



