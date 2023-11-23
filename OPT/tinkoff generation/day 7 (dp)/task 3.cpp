int *dp[1001], *pr[1001];
unsigned short* lcp[1001];
string s;

string unfold(int l, int r, string cur) {
    const int prev = pr[l][r];
    if (prev == 0) {
        return cur + s.substr(l, r - l + 1);
    }
    if (prev > 0) {
        return unfold(l + prev, r, unfold(l, l + prev - 1, cur));
    }
    return cur + to_string((r - l + 1) / -prev) + "(" +
           unfold(l, l - prev - 1, "") + ")";
}

cin >> s;
int n = s.size();
for (int i = 0; i < 1001; ++i) {
    dp[i] = (i < n ? new int[n] : nullptr);
    pr[i] = (i < n ? new int[n] : nullptr);
    lcp[i] = (i <= n ? new unsigned short[n + 1] : nullptr);
    if (lcp[i]) {
        for (int j = 0; j <= n; ++j) {
            lcp[i][j] = 0;
        }
    }
    if (dp[i]) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = 0x1FFFFFFF;
            pr[i][j] = 0;
        }
    }
}

for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= i; --j) {
        if (s[i] == s[j]) {
            lcp[i][j] = 1 + lcp[i + 1][j + 1];
        }
    }
}

for (int len = 1; len <= n; ++len) {
    for (int left = 0; left + len <= n; ++left) {
        int right = left + len - 1;  // [left; right]
        dp[left][right] = len;

        for (int m = left; m < right; ++m) {
            if (dp[left][right] > dp[left][m] + dp[m + 1][right]) {
                dp[left][right] = dp[left][m] + dp[m + 1][right];
                pr[left][right] = m - left + 1;
            }
        }

        for (int p = 1; p < len; ++p) {
            int lpr = len / p;
            int len_cur = (lpr < 10 ? 1 : lpr < 100 ? 2 : lpr < 1000 ? 3 : 4);
            if (0 == len % p && lcp[left][left + p] >= len - p) {
                if (dp[left][right] > 2 + len_cur + dp[left][left + p - 1]) {
                    dp[left][right] = 2 + len_cur + dp[left][left + p - 1];
                    pr[left][right] = -p;
                }
            }
        }
    }
}

cout << unfold(0, n - 1, "");