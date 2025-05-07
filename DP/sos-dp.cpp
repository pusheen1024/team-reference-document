vector<li> transform(vector<li> a, bool rev) {
    int n = int(a.size());
    int ln = __builtin_popcount(n - 1);
    for (int i = 0; i < ln; i++) {
        for (int j = 0; j < n; j++) {
            if ((j >> i) & 1) a[j] += (rev ? -1 : 1) * a[j ^ (1 << i)];
        }
    }
    return a;
}
