struct func {
    li k;
    li b;
    func(int k, li b) {
        this->k = k;
        this->b = b;
    }
    func() {}
    li eval(li x) {
        return k * x + b;
    }
};
func fINF(0, -INF64);
func tr[4 * N];
li x[N], y[N], a[N];
li dp[N];
void build(int v, int l, int r) {
    tr[v] = fINF;
    if (l == r - 1) return;
    int m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
}
void add(int v, int l, int r, int pos, func& f) {
    int m = (l + r) / 2;
    if (f.eval(y[m]) > tr[v].eval(y[m])) swap(f, tr[v]);
    if (l == r - 1) return;
    if (f.eval(y[l]) > tr[v].eval(y[l])) add(2 * v + 1, l, m, pos, f);
    else add(2 * v + 2, m, r, pos, f);
}
li get(int v, int l, int r, int pos) {
    li ans = tr[v].eval(y[pos]);
    if (l == r - 1) return ans;
    int m = (l + r) / 2;
    if (pos < m) ans = max(ans, get(2 * v + 1, l, m, pos));
    else ans = max(ans, get(2 * v + 2, m, r, pos));
    return ans;
}
