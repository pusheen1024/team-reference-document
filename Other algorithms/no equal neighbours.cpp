// нельзя расположить более k одинаковых элементов подряд
int sm = 0;
int mx = max_element(a.begin(), a.end()) - a.begin();
for (int i = 0; i < m; i++) {
    if (i != mx) sm += a[i];
}
if ((sm + 1) * k < a[mx]) {
    cout << -1 << '\n';
    return;
}
set<ptt> rem;
for (int i = 0; i < m; i++) {
    rem.insert({ a[i], i });
}
vector<int> ans;
ptt last = { 0, 0 };
while (!rem.empty()) {
    if ((*rem.rbegin()).second != last.first || last.second < k) {
        ptt x = (*rem.rbegin());
        ans.pb(x.second);
        if (x.second == last.first) last.second++;
        else last = { x.second, 1 };
        rem.erase(x);
        if (x.first > 1) rem.insert({ x.first - 1, x.second });
    }
    else {
        ptt x = (*rem.begin());
        ans.pb(x.second);
        last = { x.second, 1 };
        rem.erase(x);
        if (x.first > 1) rem.insert({ x.first - 1, x.second });
    }
}
