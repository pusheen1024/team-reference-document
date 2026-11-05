vector<ld> ax(n), bx(n), cx(n), dx(n);
for (int i = 0; i < n; i++) {
	if (i > 0) ax[i] = a[i][i - 1];
	bx[i] = -a[i][i];
	if (i + 1 < n) cx[i] = a[i][i + 1];
	dx[i] = a[i][n];
}
vector<ld> p(n + 1), q(n + 1);
p[1] = cx[0] / bx[0];
q[1] = -dx[0] / bx[0];
for (int i = 1; i < n; i++) {
	p[i + 1] = cx[i] / (bx[i] - ax[i] * p[i]);
	q[i + 1] = (ax[i] * q[i] - dx[i]) / (bx[i] - ax[i] * p[i]);
}
vector<ld> x(n);
x[n - 1] = q[n];
for (int i = n - 2; i >= 0; i--) {
	x[i] = p[i + 1] * x[i + 1] + q[i + 1]; 
}
