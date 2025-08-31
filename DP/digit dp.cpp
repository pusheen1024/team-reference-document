string s = to_string(r);
int n = s.size();
dp[0][0][0] = 1;
for (int i = 0; i < n; i++) {
    for (int t = 0; t < 4; t++) {
        for (int fl = 0; fl < 2; fl++) {
            if (!dp[i][t][fl]) continue;
            for (int c = 0; c <= (fl ? 9 : s[i] - '0'); c++) {
                if (t + (c != 0) <= 3) {
                    dp[i + 1][t + (c != 0)][fl | (c < s[i] - '0')] += dp[i][t][fl];
                }
            }
        }
    }
}
li kl = 0;
for (int i = 1; i <= 3; i++) kl += dp[n][i][1];
// количество чисел, в десятичной записи которых не более трёх ненулевых цифр
