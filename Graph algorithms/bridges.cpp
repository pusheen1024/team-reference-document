int dfs(int v, int p, vector<bool> &used, vector<vector<edge>> &g, vector<bool> &is_br, vector<int> &d) {
    used[v] = true;
    int ans = INF;
    for (auto e: g[v]) {
        int to = v ^ e.v ^ e.u;
        if (! used[to]) {
            d[to] = d[v] + 1;
            int mn = dfs(to, v, used, g, is_br, d);
            if (mn > d[v]) {
                is_br[e.idx] = true;
                cnt++;
            }
            ans = min(ans, mn);
        }
        else if (to != p) ans = min(ans, d[to]);
    }
    return ans;
}
