vector<int> sums(vector<int> &a) {
    int n = a.size();
    vector<int> s = {0};
    for (int i = 0; i < n; i++) {
        int k = s.size();
        for (int j = 0; j < k; j++) {
            s.pb(add(s[j], a[i]));
        }
    }
    sort(s.begin(), s.end());
    return s;
}
void solve() {
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
}
