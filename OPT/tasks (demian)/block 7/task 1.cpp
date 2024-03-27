int conv(string s) {
    int ans = 0, n = s.size();
    for (int i = 0; i < n; i++)
        if (s[i] == '1') ans += (1 << (n - i - 1));
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int prev = 0, cur = 0, next = (1 << k) - 1;

    string s;
    bool flag = false;

    while (n--) {
        cin >> s;
        if (!flag) {
            cur = conv(s);
            if (cur >= prev)
                prev = cur;
            else
                flag = !flag;
        } else
            next = conv(s);
    }

    int ans = inf, cnt;
    for (int i = 0; i < (1 << k); i++) {
        cnt = 0;
        for (int j = 0; j < k; j++)
            if (i & (1 << j)) cnt++;
        int t = cur ^ i;
        if (prev <= t && t <= next) ans = min(ans, cnt);
    }

    cout << ans << '\n';
}

int t;
cin >> t;

while (t--) solve();