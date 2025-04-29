int dfs(int v, int p, vector<bool> &used, vector<vector<int>> &g, vector<bool> &is_br, vector<int> &d) {
    used[v] = true;
    int ans = INF;
    int subtree = 0;
    for (auto u: g[v]) {
        if (! used[u]) {
            d[u] = d[v] + 1;
            int mn = dfs(u, v, used, g, is_br, d);
            if (mn >= d[v] && p != -1) {
                is_br[v] = true;
            }
            ans = min(ans, mn);
            subtree++;
        }
        else if (u != p) ans = min(ans, d[u]);
    }
    if (subtree > 1 && p == -1) {
        is_br[v] = true;
    }
    return ans;
}
