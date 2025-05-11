void topsort(int v, vector<vector<int>> &g, vector<bool> &used, vector<int> &ord) {
    used[v] = true;
    for (auto u : g[v]) {
        if (! used[u]) topsort(u, g, used, ord);
    }
    ord.push_back(v);
}
void dfs(int v, int cnt, vector<vector<int>> &tg, vector<int> &comp) {
    comp[v] = cnt;
    for (int u : tg[v]) {
        if (! comp[u]) dfs(u, cnt, tg, comp);
    }
}
void solve() {
    vector<int> comp(n);
    vector<bool> used(n);
    vector<int> ord;
    for (int i = 0; i < n; i++) {
        if (! used[i]) topsort(i, g, used, ord);
    }
    reverse(ord.begin(), ord.end());
    int cnt = 1;
    for (auto v: ord) {
        if (! comp[v]) dfs(v, cnt++, tg, comp);
    }
}
