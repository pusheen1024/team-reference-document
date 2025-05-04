vector<int> fence(vector<int> &a) {
    int n = a.size();
    vector<int> h(n);
    h[0] = -1;
    for (int i = 1; i < n; i++) {
        int cur = i - 1;
        while (cur != -1 && a[cur] >= a[i]) cur = h[cur];
        h[i] = cur;
    }
    return h;
}
