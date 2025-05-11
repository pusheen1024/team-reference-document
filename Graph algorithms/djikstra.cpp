priority_queue<ptt> q;
q.push({0, v1});
vector<bool> used(n);
vector<int> d(n, INF);
d[v1] = 0;
while (! q.empty()) {
    int v = q.top().second;
    q.pop();
    if (used[v]) continue;
    used[v] = true;
    for (auto p: g[v]) {
        int u = p.first;
        int w = p.second;
        if (d[u] > d[v] + w) {
            d[u] = d[v] + w;
            q.push({-d[u], u});
        }
    }
}
