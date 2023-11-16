int n; // запросы
int a, b; // значения


cin >> n >> a >> b;
while (n--) {
    int x;
    cin >> x;

    vector<int> dp(x + 1, 5e8);
    dp[a] = 1;
    for (int i = a + 1; i <= x; i++) {
        if (i % b == 0)
            dp[i] = min(dp[i - a], dp[i / b]) + 1;
        else dp[i] = dp[i - a] + 1;
    }

    if (dp[x] >= 5e8) {
        cout << 0 << '\n';
    } else {
        string answer = "";
        for (int i = x; i > 0;) {
            if (i % b == 0) {
                if (dp[i] == dp[i / b] + 1) {
                    answer += "B";
                    i /= b;
                } else {
                    answer += "A";
                    i -= a;
                }
            } else {
                answer += "A";
                i -= a;
            }
        }

        reverse(answer.begin(), answer.end());
        for (char &c : answer) {
            cout << c << '\n';
        }
    }
}