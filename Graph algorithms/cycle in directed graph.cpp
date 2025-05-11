bool dfs(int v, vector<vector<int>> &g, vector<int> &used, vector<int> &p, int &c_st, int &c_end) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (! used[u]) {
            p[u] = v;
            if (dfs(u, g, used, p, c_st, c_end)) return true;
        }
        if (used[u] == 1) {
            c_st = u;
            c_end = v;
            return true;
        }
    }
    used[v] = 2;
    return false;
}
void solve() {
    int c_st = -1, c_end = -1;
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        dfs(i, g, used, p, c_st, c_end);
        if (c_st != -1) {
            vector<int> cycle;
            while (c_end != c_st) {
                cycle.push_back(c_end);
                c_end = p[c_end];
            }
            cycle.push_back(c_end);
            reverse(cycle.begin(), cycle.end());
            cout << cycle.size() << '\n';
            for (int x: cycle) cout << x + 1 << ' ';
            cout << c_end + 1 << '\n';
            return;
        }
    }
}
