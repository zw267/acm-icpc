n = 50
dist = {}
dist[0] = 1
for i in range(1,n + 1):
	dist[i] = dist[i - 1] * i
res = 0
for i in range(0,26):
	for j in range(0,17):
		if(2 * i + 3 * j > n):
			break
		for k in range(0,13):
			if(2 * i + 3 * j + 4 * k > n):
				break
			u = dist[i+j+k] / dist[i] / dist[j] / dist[k]
			tmp = n - i - 2 * j - 3 * k
			v = dist[tmp] / dist[i+j+k] / dist[tmp-i-j-k]
			res += u * v
print res

