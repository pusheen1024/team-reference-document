struct edge {
    int to, w, f;
    edge(int to, int w, int f) {
        this->to = to;
        this->w = w;
        this->f = f;
    }
};
void add_edge(int fr, int to, int w) {
    g[fr].pb(e.size());
    e.pb(edge(to, w, 0));
    g[to].pb(e.size());
    e.pb(edge(fr, 0, 0));
}
int rem(edge x) {
    return x.w - x.f;
}
int dfs(int v, int f, int k, int T) {
    if (used[v]) return 0;
    used[v] = 1;
    if (v == T) return f;
    for (int i : g[v]) {
        edge &a = e[i];
        int r = rem(a);
        if (r < k) continue;
        int pushed = dfs(a.to, min(r, f), k, T);
        if (pushed) {
            a.f += pushed;
            e[i ^ 1].f -= pushed;
            return pushed;
        }
    }
    return 0;
}
void solve() {
    int ans = 0;
    for (int k = 30; k >= 0; k--) {
        int min_flow = 1 << k;
        while (true) {
            used.assign(n, 0);
            int flow = dfs(S, INF, min_flow, T);
            if (! flow) break;
            ans += flow;
        }
    }
    cout << ans << '\n';
}
