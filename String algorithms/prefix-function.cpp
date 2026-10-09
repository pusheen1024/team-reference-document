vector<int> prf(string& s) {
  int n = s.size();
  vector<int> pr(n);
  for (int i = 1; i < n; i++) {
    int j = pr[i - 1];
    while (j > 0 && s[j] != s[i]) {
      j = pr[j - 1];
    }
    if (s[i] == s[j]) j++;
    pr[i] = j;
  }
  return pr;
}
