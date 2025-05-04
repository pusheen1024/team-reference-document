dp = [0] * (sm + 1)
last = [-1] * (sm + 1)
dp[0] = 1
for i in range(n):
    for j in range(sm, -1, -1):
        if j + a[i] <= sm:
            if dp[j] and not dp[j + a[i]]:
                dp[j + a[i]] = 1
                last[j + a[i]] = i
for x in t:
    if x > sm or not dp[x]:
        print(-1)
        continue
    ans = list()
    cur = x
    while cur > 0:
        ans.append(last[cur] + 1)
        cur -= a[last[cur]]
    print(*ans[::-1])
