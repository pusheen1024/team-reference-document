vector<int> sums(vector<int> &a) {
    int n = a.size();
    vector<int> s;
    for (int i = 0; i < (1 << n); i++) {
        int sm = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) sm = add(sm, a[j]);
        }
        s.pb(sm);
    }
    sort(s.begin(), s.end());
    return s;
}

void solve() {
    int n;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k = n / 2;
    vector<int> left(a.begin(), a.begin() + k);
    vector<int> right(a.begin() + k, a.end());
    auto lsm = sums(left);
    auto rsm = sums(right);
    int ans = 0;
    for (int i = 0; i < lsm.size(); i++) {
        int j = upper_bound(rsm.begin(), rsm.end(), M - lsm[i] - 1) - rsm.begin();
        if (j > 0) ans = max(ans, add(lsm[i], rsm[j - 1]));
        ans = max(ans, add(lsm[i], rsm.back()));
    }
    cout << ans << '\n';
}
