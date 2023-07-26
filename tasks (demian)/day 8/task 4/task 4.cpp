int n;
cin >> n;

vector<vector<int>> dp(n + 1, vector<int>(3, 0));

dp[0][0] = 1;

for (int i = 50; i <= n; i++)
{
    if (i >= 50)
    {
        dp[i][0] = dp[i - 50][0];
    }
    if (i >= 100)
    {
        dp[i][1] = dp[i - 100][0] + dp[i - 100][1];
    }
    if (i >= 200)
    {
        dp[i][2] = dp[i - 200][0] + dp[i - 200][1] + dp[i - 200][2];
    }
}

cout << dp[n][0] + dp[n][1] + dp[n][2] << '\n';