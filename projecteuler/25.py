pre,now,ind = 1,1,2
def cal(x):
	res = 1
	while x >= 10:
		res += 1
		x /= 10
	return res
for i in range(3,5000):
	tmp = now
	now += pre
	pre = tmp
	ind += 1
	if(cal(now) >= 1000):
		break
print ind
