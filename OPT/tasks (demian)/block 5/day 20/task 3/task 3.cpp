int n, m;
cin >> n >> m;

vector<pair<int, int>> v(m);
for (int i = 0; i < m; i++) {
    cin >> v[i].first >> v[i].second;
    v[i].first--;
    v[i].second--;
}

int answer = 0;
for (int mask = 0; mask <= (1 << n); mask++) {
    bool flag = false;
    int b = 0;
    int r = 0;

    for (auto p : v) {
        if ((mask >> p.first & 1) == (mask >> p.second & 1)) {
            flag = true;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (mask >> i & 1)
            b++;
        else
            r++;
    }

    if (!flag) {
        if (b == r) {
            answer++;
            // for (int i = 0; i < n; i++) {
            //     cout << (mask >> i & 1);
            // }
            // cout << '\n';
        }
    }
}

cout << answer / 2 << '\n';