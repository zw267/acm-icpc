res = 0
for i in range(1000000 / 2,1000000):
	if((i & 1) == 0):continue
	s = i
	now = 1
	while(s != 1):
		if(s & 1): s = 3 * s + 1
		else: s /= 2
		now += 1
	if(now == 525): 
		res = i
		break
print res

