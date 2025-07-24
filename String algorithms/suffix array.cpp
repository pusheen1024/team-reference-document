s += '#';
int n = s.size();
vector<int> cl(n);
for (int i = 0; i < n; i++) cl[i] = s[i] - 'a';
for (int k = 1; k <= n; k <<= 1) {
    vector<array<int, 3>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = { cl[i], cl[(i + k) % n], i };
    }
    stable_sort(p.begin(), p.end());
    cl[p[0][2]] = 0;
    bool fl = 1;
    for (int i = 1; i < n; i++) {
        bool fl1 = (p[i - 1][0] != p[i][0] || p[i - 1][1] != p[i][1]);
        fl &= fl1;
        cl[p[i][2]] = cl[p[i - 1][2]] + fl1;
    }
    if (fl) break;
}
vector<int> suf(n);
for (int i = 0; i < n; i++) suf[cl[i]] = i;
