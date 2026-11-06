vector<int> coords[N];
vector<int> f[N];
void init() {
	for (int i = 0; i < N; i++) {
		coords[i].clear();
	}
}
void add1(int x, int y) {
	while (x < N) {
		coords[x].pb(y);
		x += x & -x;
	}
}
void build() {
	for (int i = 0; i < N; i++) {
		sort(coords[i].begin(), coords[i].end());
		coords[i].erase(unique(coords[i].begin(), coords[i].end()), coords[i].end());
		f[i].assign(coords[i].size() + 1, 0);
	}
}
void add2(int x, int y) {
	while (x < N) {
		int pos = lower_bound(coords[x].begin(), coords[x].end(), y) - coords[x].begin() + 1;
		while (pos < f[x].size()) {
			f[x][pos]++;
			pos += pos & -pos;
		}
		x += x & -x;
	}
}
int get(int x, int y) {
	int ans = 0;
	while (x > 0) {
		auto it = lower_bound(coords[x].begin(), coords[x].end(), y);
		if (it == coords[x].end() || *it > y) {
			if (it == coords[x].begin()) {
				x -= x & -x;
				continue;
			}
			it--;
		}
		int pos = it - coords[x].begin() + 1;
		while (pos > 0) {
			ans += f[x][pos];
			pos -= pos & -pos;
		}
		x -= x & -x;
	}
	return ans;
}
int getsum(int x, int y, int x1, int y1) {
	return get(x1, y1) - get(x - 1, y1) - get(x1, y - 1) + get(x - 1, y - 1);
}
