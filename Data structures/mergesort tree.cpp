void recalc(int v) {
    vector<int> &left = tr[2 * v + 1];
    vector<int> &right = tr[2 * v + 2];
    int i = 0;
    int j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) tr[v].pb(left[i++]);
        else tr[v].pb(right[j++]);
    }
    while (i < left.size()) tr[v].pb(left[i++]);
    while (j < right.size()) tr[v].pb(right[j++]);
}
void build(int v, int l, int r, vector<ptt> &p) {
    if (l == r - 1) {
        tr[v].pb(p[l].second);
        return;
    }
    int m = (l + r) / 2;
    build(2 * v + 1, l, m, p);
    build(2 * v + 2, m, r, p);
    recalc(v);
}
int countltX(int v, int l, int r, int L, int R, int x) {
    if (L >= R) return 0;
    if (L == l && R == r)
        return lower_bound(tr[v].begin(), tr[v].end(), x) - tr[v].begin();
    int m = (l + r) / 2;
    int left = countltX(2 * v + 1, l, m, L, min(R, m), x);
    int right = countltX(2 * v + 2, m, r, max(L, m), R, x);
    return left + right;
}
