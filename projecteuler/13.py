s = 0
f = open('data.in','r')
for eachLine in f:
	s += int(eachLine)
while s >= 10000000000:
	s /= 10
print s
