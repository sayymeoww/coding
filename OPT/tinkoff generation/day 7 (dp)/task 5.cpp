const int maxn = 10010;
vector<int> dp(maxn, 0);

int s, n;
cin >> s >> n;

dp[0] = 1;

for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    for (int j = s; j >= w; j--)
        if (dp[j - w] == 1) dp[j] = 1;
}

int i;
for (i = s;; i--)
    if (dp[i] > 0) break;
cout << i << '\n';