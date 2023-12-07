const int mod = 998'244'353;
const int inf = 2e9;
int n, m, K, a[1005][1005], dp[1005][1005][2];
bool in[1005][1005];

cin >> n >> m >> k;

for (int i = 0; i < k; i++) {
    int r, c, v;
    cin >> r >> c >> v;
    in[r][c] = true;
    a[r][c] = v;
}
for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
        if (in[i][j])
            dp[i][j][0] = dp[i][j][1] = a[i][j];
        else {
            dp[i][j][1] = max(dp[i + 1][j][0], dp[i][j + 1][0]);
            dp[i][j][0] = min(dp[i + 1][j][1], dp[i][j + 1][1]);
        }
    }
}
long long ans = 0;
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) ans += dp[i][j][0];
cout << (ans % mod + mod) % mod << '\n';