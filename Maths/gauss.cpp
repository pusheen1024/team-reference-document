vector<ld> gauss(vector<vector<ld>>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int mx = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(a[j][i]) > abs(a[mx][i])) mx = j;
        }
        swap(a[mx], a[i]);
        for (int j = n; j >= i; j--) a[i][j] /= a[i][i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                for (int k = n; k >= i; k--) {
                    a[j][k] -= a[i][k] * a[j][i];
                }
            }
        }
    }
    vector<ld> ans(n);
    for (int i = 0; i < n; i++) ans[i] = a[i][n];
    return ans;
}
