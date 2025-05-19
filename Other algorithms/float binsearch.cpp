ld l = 0;
ld r = INF;
for (int i = 0; i < 60; i++) {
    ld m = (l + r) / 2;
    if (f(m) < ans)
        l = m;
    else
        r = m;
}
cout << l << '\n';
