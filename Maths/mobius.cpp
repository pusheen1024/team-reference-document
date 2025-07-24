vector<int> m(N, 0);
m[1] = 1;
for (int i = 1; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
        m[j] -= m[i];
    }
}
