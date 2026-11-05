for (int i = 2; i < N; i++) {
    if (sieve[i]) continue;
    for (int j = i; j < N; j += i) {
        sieve[j] = (sieve[j] == 0 ? i : min(sieve[j], i));
    }
}
while (x > 1) {
    mp[sieve[x]]++;
    x /= sieve[x];
}
