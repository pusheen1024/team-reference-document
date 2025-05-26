const int K = 2;
typedef array<int, K> vec;
typedef array<vec, K> mtx;

mtx mul(const mtx &a, const mtx &b) {
    mtx res;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            res[i][j] = 0;
        }
    }
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < K ; i++) {
            for (int j = 0; j < K; j++) {
                res[i][j] = add(res[i][j], mul(a[i][k], b[k][j]));
            }
        }
    }
    return res;
}
vec mul(const mtx &a, const vec &b) {
    vec res;
    for (int i = 0; i < K; i++) {
        res[i] = 0;
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            res[i] = add(res[i], mul(a[i][j], b[j]));
        }
    }
    return res;
}
mtx unit() {
    mtx res;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            res[i][j] = (i == j ? 1 : 0);
        }
    }
    return res;
}
mtx binpow(const mtx &a, li n) {
    mtx ans = unit();
    mtx base = a;
    while (n) {
        if (n & 1) ans = mul(ans, base);
        base = mul(base, base);
        n >>= 1;
    }
    return ans;
}
void solve() { // n-ное число Фибоначчи
    li n;
    cin >> n;
    mtx T;
    T[0][0] = 0;
    T[0][1] = T[1][0] = T[1][1] = 1;
    vec f;
    f[0] = 0;
    f[1] = 1;
    vec ans = mul(binpow(T, n), f);
    cout << ans[0] << '\n';
}
