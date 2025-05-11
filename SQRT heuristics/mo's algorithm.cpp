vector<array<int, 3>> q;
for (int i = 0; i < m; i++) {
    int li, ri;
    cin >> li >> ri;
    q.pb({li, ri, i});
}
auto comp = [&] (array<int, 3> a, array<int, 3> b) {
    int a0 = a[0] / sq;
    int b0 = b[0] / sq;
    return (a0 < b0 || (a0 == b0 && (a0 % 2 == 0 ? a[1] < b[1] : a[1] > b[1])));
};
sort(q.begin(), q.end(), comp);
int l = 0;
int r = -1;
vector<int> ans(m);
vector<int> mp(n);
int d = 0;
for (int i = 0; i < m; i++) {
    int L = q[i][0];
    int R = q[i][1];
    int idx = q[i][2];
    while (l > L) {
        l--;
        if (mp[a[l]] == 0) d++;
        mp[a[l]]++;
    }
    while (r < R) {
        r++;
        if (mp[a[r]] == 0) d++;
        mp[a[r]]++;
    }
    while (l < L) {
        mp[a[l]]--;
        if (mp[a[l]] == 0) d--;
        l++;
    }
    while (r > R) {
        mp[a[r]]--;
        if (mp[a[r]] == 0) d--;
        r--;
    }
    ans[idx] = d;
}
