set<int> used;
for (int i = 0; i < n; i++) used.insert(i);
int i = 0;
vector<int> cycles;
while (! used.empty()) {
    used.erase(i);
    if (! used.count(p[i])) {
        cycles.pb(p[i]);
        i = *used.begin();
    }
    else i = p[i];
}
for (auto st : cycles) {
    vector<int> cur;
    cur.pb(st + 1);
    int i = p[st];
    while (i != st) {
        cur.pb(i + 1);
        i = p[i];
    }
    for (int x : cur) cout << x << ' ';
}
