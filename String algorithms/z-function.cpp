vector<int> zf(string& s) {
  int n = s.size();
  int l = 0, r = 0;
  vector<int> z(n);
  for (int i = 1; i < n; i++) {
    int j = max(0, min(r - i, z[i - l]));
    int k = i + j;
    while (k < n && s[k] == s[j]) {
      k++;
      j++;
    }
    z[i] = j;
    if (k > r) {
      l = i;
      r = k;
    }
  }
  return z;
}
