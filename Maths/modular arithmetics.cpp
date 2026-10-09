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
