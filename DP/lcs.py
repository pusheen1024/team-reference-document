dp = [[0] * (m + 1) for _ in range(n + 1)]
for i in range(n + 1):
    for j in range(m + 1):
        if i < n:
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j])
        if j < m:
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j])
        if i < n and j < m:
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (s[i] == t[j]))
print(dp[-1][-1])
