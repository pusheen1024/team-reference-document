vector<int> left(q, 0);
vector<int> right(q, m);
vector<int> ans(q);
vector<vector<int>> ask(m);
for (int i = 0; i < q; i++) {
    if (left[i] == right[i] - 1) ans[i] = right[i];
    else {
        int mid = (left[i] + right[i]) / 2;
        ask[mid].pb(i);
    }
}
while (true) {
    init(n);
    vector<vector<int>> nw(m);
    bool fl = 0;
    for (int i = 0; i < m; i++) {
        for (int j : ask[i]) {
            if (get(qs[j][0], qs[j][1]) >= qs[j][2]) right[j] = i;
            else left[j] = i;
            if (left[j] != right[j] - 1) {
                int mid = (left[j] + right[j]) / 2;
                nw[mid].pb(j);
                fl = 1;
            }
            else ans[j] = right[j];
        }
        merge(e[i].first, e[i].second);
    }
    ask = nw;
    if (! fl) break;
}
