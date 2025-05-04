int lis(vector<int> &v) {
    vector<int> ls;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(ls.begin(), ls.end(), v[i]);
        if (it == ls.end())
            ls.push_back(v[i]);
        else
            *it = v[i];
    }
    return ls.size();
}
