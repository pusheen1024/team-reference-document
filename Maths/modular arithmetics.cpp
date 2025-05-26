int add(int x, int y) {
	x += y;
	while (x >= M) x -= M;
	while (x < 0) x += M;
	return x;
}
int mul(int x, int y) {
    return (x * 1ll * y) % M;
}
int mod_pow(int base, int n) {
	int ans = 1;
	while (n != 0) {
		if (n & 1) ans = mul(ans, base);
		n >>= 1;
		base = mul(base, base);
	}
	return ans;
}
int gcd_(li x, li y) {
	while (x != 0 && y != 0) {
		if (x > y) swap(x, y);
		y = y % x;
	}
	return x + y;
}
int exgcd(int a, int b, li& x1, li& y1) {
	if (b == 0) {
		x1 = 1;
		y1 = 0;
		return a;
	}
	li x, y;
	int d = exgcd(b, a % b, x, y);
	x1 = y;
	y1 = x - (a / b) * y;
	return d;
}
void solve_diofantine() {
	int a, b, c;
	cin >> a >> b >> c;
	// ax + by = c
	if (a == 0 && b == 0) {
		if (c == 0) {
			cout << "YES" << '\n';
			cout << 1 << ' ' << 1 << '\n';
		}
		else cout << "NO" << '\n';
		return;
	}
	li x = 0, y = 0;
	int d = exgcd(a, b, x, y);
	if (c % d != 0) cout << "NO" << '\n';
	else {
		cout << "YES" << '\n';
		int m = c / d;
		cout << x * m << ' ' << y * m << '\n';
	}
}
