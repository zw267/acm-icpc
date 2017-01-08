def qp(x,y):
	res = 1
	while y > 0:
		if y & 1:
			res = res * x
		x = x * x
		y >>= 1
	return res

res = 0
for i in range(1,1001):
	res += qp(i,i)
res %= 10000000000
print res
