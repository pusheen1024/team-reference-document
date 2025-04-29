li mst(vector<edge> edges, vector<vector<ptt>> &g_mst) {
    sort(edges.begin(), edges.end());
    li ans = 0;
    for (edge e : edges) {
        if (merge(e.v, e.u)) {
            g_mst[e.v].pb({e.u, e.w});
            g_mst[e.u].pb({e.v, e.w});
            in_mst[e.i] = true;
            ans += e.w;
        }
    }
    return ans;
}
