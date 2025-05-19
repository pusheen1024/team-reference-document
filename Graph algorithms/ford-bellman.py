d = [INF] * n
d[0] = 0
for i in range(n - 1):
    for v, u, w in g:
        d[u] = min(d[u], d[v] + w)
