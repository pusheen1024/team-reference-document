using cd = complex<double>;
const double PI = acos(-1);
 
const int logN = 23;
cd W[1<<logN], V[1<<logN];
int rev_index[1<<logN];
 
cd get_w(int n, int k) {
    double arg = 2 * PI * k / n;
    return {cos(arg), sin(arg)};
}
 
int reveverse_bits(int k, int d) {
    int res = 0;
    for (int bit = 0; bit < d; bit++)
        res |= ((k >> bit) & 1) << (d-1-bit);
 
    return res;
}
 
void fft(vector<cd> &a, bool invert) {
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
            cd w(1);
            for (int j = 0; j < len; j++) {
                cd even = a[i+j],
                    odd = a[i+len+j];
                a[i+j] = even + ((invert) ? V[j<<(logN-deg-1)] : W[j<<(logN-deg-1)]) * odd;
                a[i+len+j] = even - ((invert) ? V[j<<(logN-deg-1)] : W[j<<(logN-deg-1)]) * odd;
            }
        }
    }
 
    if (invert)
        for (int i = 0; i < n; i++)
            a[i] /= n;
}
 
vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<cd> poly_a(a.begin(), a.end()), poly_b(b.begin(), b.end());
 
    int n = 1;
    while (n < a.size() + b.size() - 1)
        n *= 2;
 
    poly_a.resize(n);
    poly_b.resize(n);
 
    fft(poly_a, false);
    fft(poly_b, false);
 
    for (int i = 0; i < n; i++)
        poly_a[i] *= poly_b[i];
    fft(poly_a, true);
 
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(poly_a[i].real());
 
    return result;
}

int main() {
    W[0] = V[0] = cd(1);
    cd w = get_w(1 << logN, 1), v = get_w(1 << logN, -1);
    for (int i = 1; i < (1 << logN); i++) {
        W[i] = W[i-1] * w;
        V[i] = V[i-1] * v;
    }
 
    for (int i = 0; i < (1 << logN); i++)
        rev_index[i] = reveverse_bits(i, logN);
}