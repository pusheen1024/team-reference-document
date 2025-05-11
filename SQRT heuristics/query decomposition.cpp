int sq = sqrt(n);
vector<array<int, 3>> qs;
vector<li> diff(n);
for (int i = 0; i < n; i++) {
    diff[i] = a[i] - (i == 0 ? 0 : a[i - 1]);
}
for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        diff[l] += x;
        diff[r] -= x;
        qs.pb({l, r, x});
    }
    else {
        int i;
        cin >> i;
        i--;
        li ans = a[i];
        for (auto e : qs) {
            int l = e[0];
            int r = e[1];
            int x = e[2];
            if (l <= i && i < r) ans += x;
        }
        cout << ans << '\n';
    }
    if ((i + 1) % sq == 0) {
        qs.clear();
        for (int i = 1; i < n; i++) diff[i] += diff[i - 1];
        a = diff;
        for (int i = 0; i < n; i++) {
            diff[i] = a[i] - (i == 0 ? 0 : a[i - 1]);
        }
    }
}
}
