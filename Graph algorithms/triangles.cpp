auto cmp = [&](ptt ve, ptt ue) {
    int v = ve.first;
    int u = ue.first;
    return (deg[v] < deg[u] || deg[v] == deg[u] && v < u);
};
for (int i = 0; i < n; i++) sort(g[i].rbegin(), g[i].rend(), cmp);
li ans = 0;
vector<int> adj(n);
vector<int> res(m + 1);
for (int v = 0; v < n; v++) {
    for (ptt ue : g[v]) adj[ue.first] = ue.second;
    for (ptt ue : g[v]) {
        int u = ue.first;
        for (ptt we: g[u]) {
            int w = we.first;
            if (deg[w] < deg[u] || deg[w] == deg[u] && w < u) break;
            if (adj[w]) {
                res[ue.second]++;
                res[we.second]++;
                res[adj[w]]++;
            }
        }
    }
    for (ptt ue : g[v]) adj[ue.first] = 0;
}
