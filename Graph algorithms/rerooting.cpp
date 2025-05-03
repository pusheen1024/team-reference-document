int dp[N], sz[N], ans[N];

void link(int v, int to) {
    sz[v] += sz[to];
    dp[v] += dp[to] + sz[to];
}

void cut(int v, int to) {
    sz[v] -= sz[to];
    dp[v] -= dp[to] + sz[to];
}

void dfs(int v, int p, vector<vector<int>> &g) {
    sz[v] = 1;
    dp[v] = 0;
    for (int u : g[v]) {
        if (u == p) continue;
        dfs(u, v, g);
        link(v, u);
    }
}

void recalc(int v, int p, vector<vector<int>> &g) {
    ans[v] = dp[v];
    for (int u : g[v]) {
        if (u == p) continue;
        cut(v, u);
        link(u, v);
        recalc(u, v, g);
        cut(u, v);
        link(v, u);
    }
}
