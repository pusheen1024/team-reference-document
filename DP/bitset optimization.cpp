void solve() {
    int p[N];
    fill(p, p + N, -1);
    bitset<N> dp;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        auto dp2 = dp;
        dp2 |= dp << a[i];
        dp ^= dp2;

        for (int s = dp._Find_first(); s < dp.size(); s = dp._Find_next(s))
            p[s] = i;

        dp = dp2;
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int s; cin >> s;
        if (!dp[s]) {
            cout << -1 << '\n';
            continue;
        }
        int pr = p[s];
        vector<int> path;
        while (~pr) {
            path.push_back(pr + 1);
            s -= a[p[s]];
            pr = p[s];
        }
        reverse(path.begin(), path.end());
        for (auto x : path) cout << x << ' ';
        cout << '\n';
    }
}
