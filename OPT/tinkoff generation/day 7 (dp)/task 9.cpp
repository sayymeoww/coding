int n;
cin >> n;
vector<int> a(n + 1);

int sum = 0;
for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
}

if (sum % 3 != 0) {
    cout << -1 << '\n';
    return 0;
}

vector<vector<unordered_set<int>>> dp(sum / 3 + 1);
for (int i = 0; i <= sum / 3; i++) {
    vector<unordered_set<int>> temp(n - 1);
    dp[i] = temp;
}

for (int i = 1; i <= n; i++) {
    if (a[i] <= sum / 3 && dp[a[i]][1].empty()) {
        dp[a[i]][1].insert(i);
    }
}

for (int i = 2; i <= n - 1; i++) {
    for (int j = 1; j <= sum / 3; j++) {
        for (int p = 1; p <= n; p++) {
            if (j - a[p] > 0 && !dp[j - a[p]][i - 1].empty()) {
                if (!dp[j - a[p]][i - 1].count(p)) {
                    unordered_set<int> temp = dp[j - a[p]][i - 1];
                    temp.insert(p);
                    dp[j][i] = temp;
                    break;
                }
            }
        }
    }
}

for (int s = 0; s < n - 1; s++) {
    if (!dp[sum / 3][s].empty()) {
        vector<vector<unordered_set<int>>> dp2(sum / 3 + 1);
        for (int i = 0; i <= sum / 3; i++) {
            vector<unordered_set<int>> temp(n - dp[sum / 3][s].size());
            dp2[i] = temp;
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] <= sum / 3 && !dp[sum / 3][s].count(i) &&
                dp2[a[i]][1].empty()) {
                dp2[a[i]][1].insert(i);
            }
        }
        for (int i = 2; i <= n - dp[sum / 3][s].size(); i++) {
            for (int j = 1; j <= sum / 3; j++) {
                for (int p = 1; p <= n; p++) {
                    if (j - a[p] > 0 && !dp2[j - a[p]][i - 1].empty()) {
                        if (!dp2[j - a[p]][i - 1].count(p) &&
                            !dp[sum / 3][s].count(p)) {
                            unordered_set<int> temp = dp2[j - a[p]][i - 1];
                            temp.insert(p);
                            dp2[j][i] = temp;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < dp2[sum / 3].size(); i++) {
            if (!dp2[sum / 3][i].empty()) {
                string first = "", second = "", third = "";
                for (int q = 1; q <= n; q++) {
                    if (dp[sum / 3][s].count(q)) {
                        first += to_string(q) + " ";
                    } else {
                        if (dp2[sum / 3][i].count(q)) {
                            second += to_string(q) + " ";
                        } else {
                            third += to_string(q) + " ";
                        }
                    }
                }

                first.pop_back();
                second.pop_back();
                third.pop_back();

                cout << dp[sum / 3][s].size() << " " << first << '\n';
                cout << dp2[sum / 3][i].size() << " " << second << '\n';
                cout << (n - dp[sum / 3][s].size() - dp2[sum / 3][i].size())
                     << " " << third << '\n';

                return 0;
            }
        }
    }
}

cout << -1 << '\n';