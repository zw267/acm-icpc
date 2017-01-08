a = input()
list = list(a)
n = len(list)
res = 0
for i in range(0,n):
	if('0' <= a[i] and a[i] <= '9'):
		tmp = int(a[i])
	else:
	 	tmp = ord(a[i]) - 55
#	print(tmp)
	res = res * 36 + tmp
print(res)
