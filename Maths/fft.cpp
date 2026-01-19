#define _USE_MATH_DEFINES
typedef complex<double> comp;
vector<comp> coeff[K][2];
vector<int> rev[K];

void precalc() {
    for (int pw = 0; pw < K; pw++) {
        int len = 1 << pw;
        coeff[pw][0].resize(len);
        coeff[pw][1].resize(len);
        comp w = exp(-comp(M_PI / len) * 2i);
        comp w1 = exp(comp(M_PI / len) * 2i);
        comp mod = 1;
        comp mod1 = 1;
        for (int k = 0; k < len; k++) {
            coeff[pw][0][k] = mod;
            coeff[pw][1][k] = mod1;
            mod *= w;
            mod1 *= w1;
        }
        rev[pw].resize(len);
        if (pw == 0) rev[pw][0] = 0;
        else {
            int prev = 1 << (pw - 1);
            for (int k = 0; k < len; k++) {
                rev[pw][k] = (rev[pw - 1][k & (prev - 1)] << 1) | (k >= prev);
            }
        }
    }
}
vector<comp> FFT(vector<comp>& P, int pw, bool inverse = 0) {
    int n = P.size();
    for (int i = 0; i < n; i++) {
        int r = rev[pw][i];
        if (i < r) swap(P[i], P[r]);
    }
    for (int pw = 1; (1 << pw) <= n; pw++) {
        int len = 1 << pw;
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < len / 2; j++) {
                comp mod = coeff[pw][inverse][j];
                comp p_e = P[i + j];
                comp p_o = P[i + j + len / 2] * mod;
                P[i + j] = p_e + p_o;
                P[i + j + len / 2] = p_e - p_o;
            }
        }
    }
    if (inverse)
        for (int i = 0; i < n; i++) P[i] /= n;
    return P;
}
vector<int> mul(vector<int>& a, vector<int>& b) {
    int sz = 1;
    int pw = 0;
    while (sz < a.size() + b.size()) {
        sz <<= 1;
        pw++;
    }
    vector<comp> af(sz);
    vector<comp> bf(sz);
    for (int i = 0; i < a.size(); i++) af[i].real(a[i]);
    for (int i = 0; i < b.size(); i++) bf[i].real(b[i]);
    af = FFT(af, pw);
    bf = FFT(bf, pw);
    for (int i = 0; i < sz; i++) af[i] = af[i] * bf[i];
    af = FFT(af, pw, 1);
    vector<int> res(sz);
    for (int i = 0; i < sz; i++) res[i] = (round(af[i].real()) == 0 ? 0 : 1);
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}
