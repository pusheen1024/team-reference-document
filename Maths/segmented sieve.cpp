vector<bool> sieve(r - l + 1, 1);
if (l == 1) sieve[0] = 0;
for (int i = 2; i * 1ll * i <= r; i++) {
    for (li j = max(i * 1ll * i, ((l + i - 1) / i) * 1ll * i); j <= r; j += i) {
        sieve[j - l] = 0;
    }
}
