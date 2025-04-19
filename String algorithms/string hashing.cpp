const li P = 31;
const li M = 998244353;

vector<int> get_hash(string s) {
	int n = s.size();
	vector<int> f(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		f[i] = add(mul(f[i + 1], P), (s[i] - 'a' + 1));
	}
	return f;
}

int sub_hash(vector<int> &f, int j, int len) {
    int sub = add(f[j], -mul(f[j + len], mod_pow(P, len)));
    return sub;
}
