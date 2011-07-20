# Problem 15
# By: Tim Oram

layer = [0] * 41

layer[20] = 1

# bottom half of triangle
for i in range(1, 20):
	
	layer_tmp = [0] * 41
	
	for j in range(20-i, 21 + i, 2):
		layer_tmp[j] = layer[j-1] + layer[j+1]
	
	# copy from tmp to actual
	layer = []
	layer.extend(layer_tmp)

# center layer
layer_tmp[0] = 1
layer_tmp[40] = 1
for j in range(2, 39, 2):
	layer_tmp[j] = layer[j-1] + layer[j+1]
	

# copy from tmp to actual
layer = []
layer.extend(layer_tmp)

# top half of triangle
for i in range(19, -1, -1):
	
	for j in range(20 - i, 21 + i, 2):
		layer_tmp[j] = layer[j-1] + layer[j+1]
	
	# copy from tmp to actual
	layer = []
	layer.extend(layer_tmp)
	
print "Answer:", layer[20]