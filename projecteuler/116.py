n = 50
dist = {}
dist[0] = 1
for i in range(1,n + 1):
	dist[i] = dist[i-1] * i
res = 0
for i in range(1,n / 2 + 1):
	res += dist[n-i] / dist[i] / dist[n - 2 * i]
for i in range(1,n / 3 + 1):
	res += dist[n - 2 * i] / dist[i] / dist[n - 3 * i]
for i in range(1,n / 4 + 1):
	res += dist[n - 3 * i] / dist[i] / dist[n - 4 * i]
print res
