set<pair<int, int>> edges;

void dfs(int v, vector<vector<int>> &g, vector<int> &used) {
    used[v] = 1;
    for (int u: g[v]) {
        if (! edges.count({v, u}) && ! edges.count({u, v})) edges.insert({v, u});
        if (! used[u]) dfs(u, g, used);
    }
}
