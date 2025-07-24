vector<vector<int>> divs(n + 1);
for (int i = 2; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
        divs[j].push_back(i);
    }
}
