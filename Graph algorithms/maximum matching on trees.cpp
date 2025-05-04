ptt dp[N][2];

ptt best(ptt x, ptt y) {
    if (x.first > y.first) return x;
    else if (y.first > x.first) return y;
    else return {x.first, add(x.second, y.second)};
}

ptt merge(ptt x, ptt y) {
    return {x.first + y.first, mul(x.second, y.second)};
}

void dfs(int v, int p, vector<vector<int>> &g) {
    vector<ptt> dp0;
    vector<ptt> dp1;
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u, v, g);
            dp0.pb(dp[u][0]);
            dp1.pb(dp[u][1]);
        }
    }
    int n = dp0.size();
    vector<ptt> pr(n + 1, {0, 1});
    vector<ptt> suf(n + 1, {0, 1});
    for (int i = 0; i < n; i++) pr[i + 1] = merge(pr[i], best(dp0[i], dp1[i]));
    for (int i = n - 1; i >= 0; i--) suf[i] = merge(suf[i + 1], best(dp0[i], dp1[i]));
    dp[v][0] = pr[n];
    for (int i = 0; i < n; i++) {
        dp[v][1] = best(dp[v][1], merge(merge(pr[i], suf[i + 1]), {dp0[i].first + 1, dp0[i].second}));
    }
}
