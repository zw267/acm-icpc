s = input()
n = int(s)
res = 1
for i in range(2,n + 1):
	res = res * i
s = str(res)
n = len(s)
j = 0
for i in range(0,n):
	print(s[i],end="")
	j += 1
	if(j == 1000):
		print('\n')
		j = 0
if(j > 0):
	print('')
