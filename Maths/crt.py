def CRT(a, m):
    # returns x such that x % m[i] == a[i]
    n = len(a)
    M = 1
    for i in range(n):
        M *= m[i]
    z = [M // m[i] for i in range(n)]
    y = [z[i] * inv(z[i], m[i]) % M for i in range(n)]
    x = 0
    for i in range(n):
        x = (x + y[i] * a[i]) % M
    return x
