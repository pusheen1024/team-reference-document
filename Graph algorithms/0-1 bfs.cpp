deque<int> q;
q.pb(0);
vector<int> d(n);
d[0] = 0;
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto& [u, w] : g[v]) {
        if (d[u] > d[v] + w) {
            d[u] = d[v] + w;
            if (w == 0) q.push_front(u);
            else q.push_back(u);
        }
    }
}
