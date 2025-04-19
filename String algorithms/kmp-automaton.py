def kmp(s):
    n = len(s)
    pr = prefix_function(s)
    aut = [[0] * 26 for _ in range(n + 1)]
    for i in range(n + 1):
        for j in range(26):
            if i < n and s[i] == chr(ord('A') + j):
                aut[i][j] = i + 1
            elif i == 0:
                aut[i][j] = 0
            else:
                aut[i][j] = aut[pr[i - 1]][j]
    return aut
