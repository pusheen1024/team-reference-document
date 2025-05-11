mt19937 rnd(time(NULL));
set<int> used;
used.insert(0);
for (int i = 0; i < int(b.size()); i++) {
    int x = rnd();
    while (used.count(x)) x = rnd();
    b[i] = x;
    used.insert(x);
}
for (int i = 0; i < n; i++) a[i] = b[a[i]];
vector<int> pr(n + 1, 0);
for (int i = 0; i < n; i++) pr[i + 1] = pr[i] ^ a[i];
// pr[l - 1] ^ pr[r] == 0 -> все элементы на отрезке [l; r] встречаются чётное количество раз
