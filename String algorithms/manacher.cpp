vector<int> manacher_odd(string& s) {
  int l = 0, r = 1, c = 0;
  int n = s.size();
  vector<int> m(n);
  m[0] = 1;
  for (int i = 1; i < n; i++) {
    int idx = c - (i - c);
    int j = i - 1;
    int k = i + 1;
    if (idx >= l) {
      int len = max(min(r - i, m[idx] / 2 + 1), 0);
      j = i - len;
      k = i + len;
    }
    while (j >= 0 && k < n && s[j] == s[k]) {
      j--;
      k++;
    }
    m[i] = k - j - 1;
    if (k > r) {
      l = j + 1;
      r = k;
      c = i;
    }
  }
  return m;
}
string s1 = "";
for (char x : s) {
  s1 += x;
  s1 += '#';
}
auto tmp = manacher_odd(s1);
vector<int> deven;
for (int i = 1; i < tmp.size() - 1; i += 2) deven.pb(tmp[i]);
for (int &x : deven) x = ((x / 2 + 1) / 2) * 2;
