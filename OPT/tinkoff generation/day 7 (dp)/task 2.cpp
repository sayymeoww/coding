int n, m;

cin >> n;
vector<int> a(n);
for (int i = 0; i < n; i++) cin >> a[i];

cin >> m;
vector<int> b(m);
for (int i = 0; i < m; i++) cin >> b[i];

int ans = 0;
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        if (a[i - 1] == b[j - 1]) {
            dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
            ans = max(ans, dp[i][j]);
        }
    }
}

cout << ans << '\n';