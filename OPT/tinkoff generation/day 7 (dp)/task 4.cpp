int n, m;

cin >> n;
vector<int> a(n);
for (auto& i : a) cin >> i;

cin >> m;
vector<int> b(m);
for (auto& i : b) cin >> i;

vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
vector<vector<pair<int, int>>> prev(n + 1,
                                    vector<pair<int, int>>(m + 1, {0, 0}));

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        if (a[i - 1] == b[j - 1]) {
            int mx = 0;
            int curr_idx = 1;
            for (int k = 1; k <= j; k++) {
                if (b[k - 1] < b[j - 1]) {
                    if (mx <= dp[i - 1][k]) {
                        mx = dp[i - 1][k];
                        curr_idx = k;
                    }
                }
            }
            dp[i][j] = 1 + mx;
            prev[i][j] = {i - 1, curr_idx};
        } else {
            dp[i][j] = dp[i - 1][j];
            prev[i][j] = {i - 1, j};
        }
    }
}

int idi = n;
int idj = 1;
int max_ans = 0;
for (int i = 1; i <= m; i++) {
    if (dp[n][i] >= max_ans) {
        idj = i;
        max_ans = dp[n][i];
    }
}

if (max_ans == 0 && a[0] == b[0]) {
    cout << 1 << '\n';
    cout << a[0] << '\n';
    return 0;
} else if (max_ans == 0) {
    cout << 0 << '\n';
    return 0;
}

vector<int> ans;
int prev_j = -1;
while (true) {
    if (idj != prev_j) {
        prev_j = idj;
        ans.emplace_back(b[idj - 1]);
        max_ans--;
    }
    idj = prev[idi][idj].second;
    idi = prev[idi][idj].first;
    if (max_ans == 0) break;
}

cout << ans.size() << '\n';
reverse(all(ans));
for (auto& i : ans) {
    cout << i << ' ';
}
cout << '\n';