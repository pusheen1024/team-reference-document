int f[N];
int mex(vector<int> &a) {
    int n = a.size();
    vector<bool> used(n + 1);
    for (int i = 0; i < n; i++) {
        if (a[i] <= n) used[a[i]] = true;
    }
    for (int i = 0; i <= n; i++) {
        if (! used[i]) return i;
    }
    return -1;
}
int gr(int x) {
    if (f[x] != -1) return f[x];
    vector<int> trans;
    for (int i = 1; i <= x; i++) {
        trans.push_back(x - i);
    }
    return (f[x] = mex(trans));
}
// функция Гранди для комбинации игр = XOR-сумма функций Гранди для каждой из игр
// XOR-сумма = 0 -> выигрывает 2ой игрок
// XOR-сумма != 0 -> выигрывает 1ый игрок
