int T[lg][N];
void build(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) T[0][i] = a[i];
    for (int i = 1; i < lg; i++) {
        int len = 1 << (i - 1);
        for (int j = 0; j + (len << 1) <= n; j++) {
            T[i][j] = __gcd(T[i - 1][j], T[i - 1][j + len]);
        }
    }
}
int query(int l, int r) {
    int len = 32 - __builtin_clz(r - l);
    len--;
    return __gcd(T[len][l], T[len][r - (1 << len)]);
}
