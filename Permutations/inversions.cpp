vector<int> merge_sort(int l, int r, li &inv) {
    if (l >= r) return {p[l]};
    int m = (l + r) / 2;
    auto left = merge_sort(l, m, inv);
    auto right = merge_sort(m + 1, r, inv);
    int i = 0;
    int j = 0;
    vector<int> res;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            inv += j;
            res.pb(left[i++]);
        }
        else res.pb(right[j++]);
    }
    while (i < left.size()) {
        res.pb(left[i++]);
        inv += j;
    }
    while (j < right.size()) {
        res.pb(right[j++]);
    }
    return res;
}
