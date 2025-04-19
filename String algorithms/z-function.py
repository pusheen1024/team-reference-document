def z(s):
    n = len(s)
    z = [0] * n
    l, r = 0, 0
    for i in range(1, n):
        j = max(0, min(z[i - l], r - i))
        while i + j < n and s[j] == s[i + j]:
            j += 1
        z[i] = j
        if i + j > r:
            l = i
            r = i + j
    return z
