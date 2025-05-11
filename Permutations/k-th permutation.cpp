vector<int> ans(n);
vector<bool> used(n + 1);
for (int i = 0; i < n; i++) {
    int num = -1;
    for (int j = 1; j <= n; j++) {
        if (used[j]) continue;
        if (cnt + fact[n - i - 1] < k) cnt += fact[n - i - 1];
        else {
            num = j;
            break;
        }
    }
    ans[i] = num;
    used[num] = true;
}
