vector<vector<int>> idx(n, vector<int> (n, 0));
vector<vector<int>> b(n, vector<int> (n, 0));
auto reduce = [&](vector<int>& v) {
    vector<int> x = v;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        if (x[i]) {
            for (int j = 0; j < n; j++) {
                x[j] ^= b[i][j];
            }
            for (int id = 0; id < n; id++) s[id] += idx[i][id];
        }
    }
    return make_pair(x, s);
};
auto add = [&](vector<int>& v, int index) {
    auto [x, s] = reduce(v);
    if (count(x.begin(), x.end(), 1) == 0) return;
    int id = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == 1) {
            id = i;
            break;
        }
    }
    b[id] = x;
    for (int z = 0; z < n; z++) idx[id][z] += s[z];
    idx[id][index]++;
};
