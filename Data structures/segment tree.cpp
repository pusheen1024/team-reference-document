void build(int v, int l, int r) {
    if (l == r - 1) {
        T[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
    T[v] = T[2 * v + 1] + T[2 * v + 2];
}
void push(int v, int l, int r) {
    if (l != r - 1) {
        ps[2 * v + 1] += ps[v];
        ps[2 * v + 2] += ps[v];
    }
    T[v] += ps[v] * (r - l);
    ps[v] = 0;
}
void upd(int v, int l, int r, int L, int R, int val) {
    push(v, l, r);
    if (L >= R) return;
    if (l == L && r == R) {
        ps[v] = val;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * v + 1, l, m, L, min(m, R), val);
    upd(2 * v + 2, m, r, max(m, L), R, val);
    T[v] = T[2 * v + 1] + T[2 * v + 2];
}
int query(int v, int l, int r, int pos) {
    push(v, l, r);
    if (l == r - 1) return T[v];
    int m = (l + r) / 2;
    int res = 0;
    if (pos < m) {
        res = query(2 * v + 1, l, m, pos);
        push(2 * v + 2, m, r);
    }
    else {
        res = query(2 * v + 2, m, r, pos);
        push(2 * v + 1, l, m);
    }
    T[v] = T[2 * v + 1] + T[2 * v + 2];
    return res;
}
// Спуск по ДО
int trav(int v, int l, int r, int x) {
    if (l == r - 1) return T[v] >= x ? l : -1;
    int m = (l + r) / 2;
    if (T[2 * v + 1] >= x) return trav(2 * v + 1, l, m, x);
    else return trav(2 * v + 2, m, r, x);
}
