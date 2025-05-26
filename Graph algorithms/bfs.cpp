vector<int> d(n, INF);
queue<int> q;
q.push(s);
d[s] = 0;
while (! q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v]) {
        if (d[u] == INF) {
            d[u] = d[v] + 1;
            q.push(u);
        }
    }
}
