class Edge:
    def __init__(self, to, w, f):
        self.to = to
        self.w = w
        self.f = f
       
def add_edge(fr, to, w):
    g[fr].append(len(e))
    e.append(Edge(to, w, 0))
    g[to].append(len(e))
    e.append(Edge(fr, 0, 0))

def rem(edge):
    return edge.w - edge.f

def dfs(v, f, k):
    if used[v]:
        return 0
    used[v] = True
    if v == T:
        return f
    for idx in g[v]:
        a = e[idx]
        r = rem(a)
        if r < k:
            continue
        pushed = dfs(a.to, min(r, f), k)
        if pushed:
            a.f += pushed
            e[idx ^ 1].f -= pushed
            return pushed
    return 0

S = 0
T = n - 1
ans = 0
for k in range(30, -1, -1):
    min_flow = 2 ** k
    while True:
        used = [False] * n
        flow = dfs(S, INF, min_flow)
        if not flow:
            break
        ans += flow
print(ans)
