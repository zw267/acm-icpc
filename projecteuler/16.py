s = 1
for i in range(1,1001):
	s *= 2
res = 0
while s > 0:
	res += s % 10
	s /= 10
print res
