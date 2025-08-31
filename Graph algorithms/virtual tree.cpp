auto cmp = [&](int v, int u) {
    return (tin[v] < tin[u]);
};
sort(a.begin(), a.end(), cmp);
for (int i = 1; i < k; i++) a.pb(lca(a[i], a[i - 1]));
sort(a.begin(), a.end(), cmp);
a.erase(unique(a.begin(), a.end()), a.end());
vector<int> st;
vector<ptt> e;
for (int i = 0; i < a.size(); i++) {
    while (!st.empty() && !is_anc(st.back(), a[i])) st.pop_back();
    if (!st.empty()) e.pb({ st.back(), a[i] });
    st.pb(a[i]);
}
