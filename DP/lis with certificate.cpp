auto func = [&](int i, int j) {
    return s[i] < s[j];
};
vector<int> lis;
vector<int> pr(n, -1);
for (int i = 0; i < n; i++) {
    auto it = lower_bound(lis.begin(), lis.end(), i, func);
    if (it == lis.end()) {
        if (it != lis.begin())
            pr[i] = *(prev(it));
        lis.push_back(i);
    }
    else {
        if (it != lis.begin())
            pr[i] = *(prev(it));
        *it = i;
    }
}
vector<int> dp(n);
for (int i = 0; i < n; i++) {
    if (pr[i] == -1) dp[i] = 1;
    else dp[i] = dp[pr[i]] + 1;
}
cout << *max_element(dp.begin(), dp.end()) << '\n';
