def pr(s):
    n = len(s)
    pr = [0] * n
    for i in range(1, n):
        j = pr[i - 1]
        while j > 0 and s[j] != s[i]:
            j = pr[j - 1]
        if s[i] == s[j]:
            j += 1
        pr[i] = j
    return pr
