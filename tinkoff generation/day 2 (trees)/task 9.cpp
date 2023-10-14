const int inf = 1e6;
const int maxn = 1e5 + 1;

int n, v;
vector<int> a(maxn), c(maxn);
vector<vector<int>> dp(maxn, vector<int>(2, inf));

void change(int cur, int op, int cost) {
    int t3;
    for (int t1 = 0; t1 < 2; t1++) {
        for (int t2 = 0; t2 < 2; t2++) {
            if (op == 1)
                t3 = (t1 && t2);
            else
                t3 = (t1 || t2);
            if (dp[cur][t3] > dp[2 * cur][t1] + dp[2 * cur + 1][t2] + cost) {
                dp[cur][t3] = dp[2 * cur][t1] + dp[2 * cur + 1][t2] + cost;
            }
        }
    }
}

cin >> n >> v;

for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i <= (n - 1) / 2)
        cin >> c[i];
    else
        dp[i][a[i]] = 0;
}

for (int i = (n - 1) / 2; i >= 1; i--) {
    change(i, a[i], 0);
    if (c[i] == 1) change(i, 1 - a[i], 1);
}

if (dp[1][v] == inf)
    cout << "IMPOSSIBLE" << '\n';
else
    cout << dp[1][v] << '\n';