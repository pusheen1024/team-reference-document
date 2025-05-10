cnt = 0
for i in range(n):
    diff = 0
    for j in range(i):
        if a[j] < a[i]:
            diff += 1
    cnt += (a[i] - diff - 1) * fact[n - i - 1]
print(cnt + 1)
