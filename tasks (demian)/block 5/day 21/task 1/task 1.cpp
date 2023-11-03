int n;
cin >> n;

vector<bool> used(2 * n, false);
vector<pair<int, int>> games(2 * n);

for (int i = 0; i < 2 * n; i++) {
    cin >> games[i].first >> games[i].second;
}

cout << "YES" << '\n';
for (int i = 0; i < 2 * n; i++) {
    if (!used[i]) {
        cout << i + 1 << '\n';
        used[i] = true;
        for (int j = 0; j < 2 * n; j++) {
            if (games[j].first == games[i].first ||
                games[j].second == games[i].second) {
                used[j] = true;
            }
        }
    }
}