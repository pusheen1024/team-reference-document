vector<array<int, 3>> q;
for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    q.pb({l, r, i});
}
int sq = sqrt(n);
auto comp = [&] (array<int, 3> a, array<int, 3> b) {
    int a0 = a[0] / sq;
    int b0 = b[0] / sq;
    return (a0 < b0 || (a0 == b0 && (a0 % 2 == 0 ? a[1] < b[1] : a[1] > b[1])));
};
sort(q.begin(), q.end(), cmp);
int l = 0;
int r = -1;
int d = 0;
vector<int> ans(m);
vector<int> mp(n + 1);
auto add = [&](int x, int fl) {
    if (x > n) return;
    if (mp[x] == x) d--;
    mp[x] += fl;
    if (mp[x] == x) d++;
};
for (int i = 0; i < m; i++) {
    int L = q[i][0];
    int R = q[i][1];
    int idx = q[i][2];
    while (l > L) {
        add(a[--l], 1);
    }
    while (r < R) {
        add(a[++r], 1);
    }
    while (l < L) {
        add(a[l++], -1);
    }
    while (r > R) {
        add(a[r--], -1);
    }
    ans[idx] = d;
}
