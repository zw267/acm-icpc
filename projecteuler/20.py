s = 1
for i in range(2,101):
	s *= i
res = 0
while s > 0:
	res += s % 10
	s /= 10
print res
