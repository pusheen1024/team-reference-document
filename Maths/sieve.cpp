bool sieve[N];

void create_sieve() {
    for (int i = 0; i < N; i++) sieve[i] = 0;
    for (int i = 2; i * i < N; i++) {
        if (!sieve[i]) {
            for (int j = i * i; j < N; j += i) {
                if (!sieve[j])
                    sieve[j] = 1;
            }
        }
    }
}

