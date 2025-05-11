int up[N][lg];
int min_up[N][lg];
int tin[N], tout[N];
int t = 0;
void dfs(int v, int p, int w, vector<vector<ptt>> &g) {
    tin[v] = t++;
    for (ptt e : g[v]) {
        int u = e.first;
        int w = e.second;
        if (u == p) continue;
        up[u][0] = v;
        min_up[u][0] = w;
        for (int i = 1; i < lg; i++) {
            up[u][i] = up[up[u][i - 1]][i - 1];
            min_up[u][i] = min(min_up[u][i - 1], min_up[up[u][i - 1]][i - 1]);
        }
        d[u] = d[v] + 1;
        dfs(u, v, w, g);
    }
    tout[v] = t;
}
bool is_ancestor(int v, int u) {
    return (tin[v] <= tin[u] && tout[v] >= tout[u]);
}
int lca(int v, int u) {
    if (is_ancestor(v, u)) return v;
    if (is_ancestor(u, v)) return u;
    int cur = v;
    for (int i = lg - 1; i >= 0; i--) {
        if (! is_ancestor(up[cur][i], u)) {
            cur = up[cur][i];
        }
    }
    return up[cur][0];
}
int min_vert(int v, int u) {
    if (v == u) return INF;
    int ans = INF;
    int cur = v;
    for (int i = lg - 1; i >= 0; i--) {
        if (! is_ancestor(up[cur][i], u)) {
            ans = min(ans, min_up[cur][i]);
            cur = up[cur][i];
        }
    }
    return min(min_up[cur][0], ans);
}
int min_path(int v, int u) {
    if (is_ancestor(v, u)) return min_vert(u, v);
    if (is_ancestor(u, v)) return min_vert(v, u);
    int lc = lca(v, u);
    return min(min_vert(v, lc), min_vert(u, lc));
}
int dist(int v, int u) {
    return d[v] + d[u] - 2 * d[lca(v, u)];
}
