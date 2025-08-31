int* where[N * 3];
int val[N * 3];
int p[N];
int sz[N];
int col[N];
int cur = 0;
void init(int n) {
    for (int i = 0; i < n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
}
void change(int &v, int x) {
    where[cur] = &v;
    val[cur] = v;
    cur++;
    v = x;
}
void rollback() {
    cur--;
    (*where[cur]) = val[cur];
}
int get_leader(int v) {
    return (v == p[v] ? v : get_leader(p[v]));
}
int get_len(int v) {
    return (v == p[v] ? 0 : (col[v] ^ get_len(p[v])));
}
bool merge(int v, int u) {
    int c = 0;
    c ^= get_len(v);
    c ^= get_len(u);
    if (get_leader(v) == get_leader(u)) return c;
    v = get_leader(v);
    u = get_leader(u);
    if (sz[v] > sz[u]) swap(v, u);
    change(sz[u], sz[u] + sz[v]);
    change(p[v], u);
    change(col[v], c ^ 1);
    return 1;
}
vector<ptt> qs;
vector<ptt> edges;
vector<int> tr[4 * N];
vector<int> ans;
void upd(int v, int l, int r, int L, int R, int e) {
    if (l == L && r == R) {
        tr[v].pb(e);
        return;
    }
    if (L >= R) return;
    int m = (l + r) / 2;
    upd(2 * v + 1, l, m, L, min(R, m), e);
    upd(2 * v + 2, m, r, max(L, m), R, e);
}
void trav(int v, int l, int r, bool fl) {
    int c = cur;
    for (int e : tr[v]) {
        fl &= merge(edges[e].first, edges[e].second);
    }
    if (l == r - 1) ans.pb(fl);
    else {
        int m = (l + r) / 2;
        trav(2 * v + 1, l, m, fl);
        trav(2 * v + 2, m, r, fl);
    }
    while (cur > c) rollback();
}
void solve() {
    init(n);
    sort(edges.begin(), edges.end());
    edges.erase(unique(edges.begin(), edges.end()), edges.end());
    vector<int> lst(edges.size(), -1);
    int i = 0;
    for (ptt q : qs) {
        int e = lower_bound(edges.begin(), edges.end(), q) - edges.begin();
        if (lst[e] == -1) lst[e] = i;
        else {
            upd(1, 0, m, lst[e], i, e);
            lst[e] = -1;
        }
        i++;
    }
    for (int e = 0; e < edges.size(); e++) {
        if (lst[e] != -1) upd(1, 0, m, lst[e], i, e);
    }
    trav(1, 0, m, 1);
}

