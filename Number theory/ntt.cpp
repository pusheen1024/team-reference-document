const int logN = 22;
const int MAGIC_CONSTANT = binpow(3, (MOD - 1) / (1 << logN));
int W[1<<logN], V[1<<logN];
int rev_index[1<<logN];
 
int get_w(int n, int k) {
    return binpow(MAGIC_CONSTANT, k * (1 << logN) / n);
}
 
int reveverse_bits(int k, int d) {
    int res = 0;
    for (int bit = 0; bit < d; bit++)
        res |= ((k >> bit) & 1) << (d-1-bit);
 
    return res;
}
 
void fft(vector<int> &a, bool invert) {
    int n = a.size();
    int d = 0;
    {
        int temp = n;
        while (temp > 1) {
            temp /= 2;
            d++;
        }
    }
 
    for (int i = 0; i < n; i++)
        if (i < (rev_index[i] >> (logN - d)))
            swap(a[i], a[(rev_index[i] >> (logN - d))]);
 
    for (int deg = 0; deg < d; deg++) {
        int len = (1 << deg);
        for (int i = 0; i < n; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int even = a[i+j],
                    odd = a[i+len+j];
                a[i+j] = add(even, mul(((invert) ? V[j<<(logN-deg-1)] : W[j<<(logN-deg-1)]), odd));
                a[i+len+j] = sub(even, mul(((invert) ? V[j<<(logN-deg-1)] : W[j<<(logN-deg-1)]), odd));
            }
        }
    }
 
    if (invert) {
        int inv_n = binpow(n, MOD-2);
        for (int i = 0; i < n; i++)
            a[i] = mul(a[i], inv_n);
    }
}
 
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<int> poly_a(a.begin(), a.end()), poly_b(b.begin(), b.end());
 
    int n = 1;
    while (n < a.size() + b.size() - 1)
        n *= 2;
 
    poly_a.resize(n);
    poly_b.resize(n);
 
    fft(poly_a, false);
    fft(poly_b, false);
 
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = mul(poly_a[i], poly_b[i]);
    fft(result, true);
 
    while (!result.empty() && result.back() == 0)
        result.pop_back();
 
    return result;
}
 
int main() {
    for (int i = 0; i < (1 << logN); i++)
        rev_index[i] = reveverse_bits(i, logN);
 
    W[0] = V[0] = 1;
    int w = get_w(1 << logN, 1), v = binpow(w, MOD-2);
    for (int i = 1; i < (1 << logN); i++) {
        W[i] = mul(W[i-1], w);
        V[i] = mul(V[i-1], v);
    }
}