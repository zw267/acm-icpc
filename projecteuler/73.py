def gcd(x,y):
	if y == 0:
		return x
	return gcd(y,x % y)

res = 0
d = 12000
for i in range(1,d+1):
	for j in range(i / 3 + 1,i / 2 + 1):
		if(j + j == i): break
		if(gcd(i,j) == 1):
			res += 1
print res
