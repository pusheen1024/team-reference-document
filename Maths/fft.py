from math import pi, e, log 
 
def FFT(P, inverse=0):
    n = len(P)
    if n == 1:
        return P
    p_e = FFT(P[::2], inverse)
    p_o = FFT(P[1::2], inverse)
    w = e ** ((-1) ** (inverse + 1) * 2j * pi / n)
    y = [0] * n
    mod = 1
    for j in range(n // 2):
        y[j] = (p_e[j] + p_o[j] * mod) / (inverse + 1)
        y[j + n // 2] = (p_e[j] - p_o[j] * mod) / (inverse + 1)
        mod *= w
    return y
