sq = int(n ** 0.5)
b = [0] * (sq + 2)
for i in range(n):
    b[i // sq] += a[i]
for _ in range(m):
    q = [int(x) for x in input().split()]
    if q[0] == 0:
        t, l, r = q
        l -= 1
        r -= 1
        sm = 0
        while l <= r:
            if l % sq == 0 and l + sq <= r:
                sm += b[l // sq]
                l += sq
            else:
                sm += a[l]
                l += 1
        print(sm)
    else:
        t, i, x = q
        i -= 1
        b[i // sq] += (x - a[i])
        a[i] = x
