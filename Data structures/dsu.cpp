int p[N], sz[N];
void init() {
    for (int i = 0; i < N; i++) {
        sz[i] = 1;
        p[i] = i;
    }
}
int get_leader(int v) {
    if (v == p[v]) return v;
    return (p[v] = get_leader(p[v]));
}
bool merge(int v, int u) {
    v = get_leader(v);
    u = get_leader(u);
    if (v == u) return false;
    if (sz[v] > sz[u]) swap(v, u);
    p[v] = u;
    sz[u] += sz[v];
    return true;
}
