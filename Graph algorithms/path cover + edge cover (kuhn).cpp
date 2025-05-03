int mt[N];

bool dfs(int v, vector<vector<int>>& g) {
    if (used[v]) return false;
    used[v] = true;
    for (int u : g[v]) {
        if (mt[u] == -1 || dfs(mt[u], g)) {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

void path_cover() {
    for (int i = 0; i < N; i++) mt[i] = -1;
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < N; i++) used[i] = false;
        dfs(i, g);
    }
    int kl = 0;
    for (int i = 0; i < N; i++) {
        if (mt[i] != -1) {
            kl++;
        }
    }
    cout << n - kl << '\n';
    vector<vector<int>> paths(n, vector<int> (0));
    for (int i = 0; i < n; i++) {
        int cur = i;
        vector<int> ans;
        while (cur != -1) {
            ans.push_back(cur + 1);
            cur = mt[cur];
        }
        reverse(ans.begin(), ans.end());
        if (paths[ans[0] - 1].size() < ans.size()) {
            paths[ans[0] - 1] = ans;
        }
    }
}

void edge_cover() {
    for (int i = 0; i < N; i++) mt[i] = -1;
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < N; i++) used[i] = false;
        dfs(i, g);
    }
    int kl = 0;
    vector<pair<int, int>> mec;
    vector<bool> cov_l(n, false);
    vector<bool> cov_r(m, false);
    for (int i = 0; i < N; i++) {
        if (mt[i] != -1) {
            kl++;
            mec.push_back(make_pair(mt[i] + 1, i + 1));
            cov_l[mt[i]] = true;
            cov_r[i] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!cov_l[i]) {
            if (g[i].size() > 0) {
                mec.push_back(make_pair(i + 1, g[i].front() + 1));
                kl++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (!cov_r[i]) {
            if (g1[i].size() > 0) {
                mec.push_back(make_pair(g1[i].front() + 1, i + 1));
                kl++;
            }
        }
    }
}
