res = []
for i in range(2,101):
	for j in range(2,101):
		res.append(i ** j)
res = set(res)
print len(res)

