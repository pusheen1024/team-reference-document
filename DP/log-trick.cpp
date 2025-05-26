vector<int> w; // веса
vector<int> c; // стоимости
for (auto& [x, y] : mp) {
    int cur = 0;
    for (int i = 0; i < 18; i++) {
        if (cur + (1 << i) <= y) {
            cur += (1 << i);
            w.pb((1 << i) * x);
            c.pb(1 << i);
        }
        else break;
    }
    for (int i = 0; i < 18; i++) {
        if ((y - cur) & (1 << i)) {
            w.pb((1 << i) * x);
            c.pb(1 << i);
        }
    }
}
