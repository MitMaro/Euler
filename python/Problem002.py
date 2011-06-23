# Problem 2
# By: Tim Oram
#
# Runtime: 0.018s

a = 1
b = 2
t = 0
while b < 4000000:
	if (b%2) == 0:
		t += b
	tmp = a
	a = b
	b =  tmp + a

print t
