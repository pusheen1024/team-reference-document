vector<int> g[N];
vector<ptt> ord;
int d[N];
int idx[N];
ptt T[lg][N];
void dfs(int v, int p) {
    ord.pb({d[v], v});
    for (int u : g[v]) {
        if (u != p) {
            d[u] = d[v] + 1;
            dfs(u, v);
            ord.pb({d[v], v});
        }
    }
}
void build(int n) {
    for (int i = 0; i < N; i++) idx[i] = -1;
    for (int i = 0; i < n; i++) {
        if (idx[ord[i].second] == -1)
            idx[ord[i].second] = i;
    }
    for (int i = 0; i < n; i++) T[0][i] = ord[i];
    for (int i = 1; i < lg; i++) {
        int len = 1 << (i - 1);
        for (int j = 0; j + len < n; j++) {
            T[i][j] = min(T[i - 1][j], T[i - 1][j + len]);
        }
    }
}
int lca(int v, int u) {
    v = idx[v];
    u = idx[u];
    if (v > u) swap(v, u);
    u++;
    int x = __lg(u - v);
    int len = 1 << x;
    return min(T[x][v], T[x][u - len]).second;
}
