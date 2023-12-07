int t, n, k;
vector<pair<int, int>> partas;

int ans = inf;

inline void solve() {
    int temp = 0, h, d;
    for (int i = 0; i < 2 * n; i++) {
        cin >> h;
        d = inf;
        bool flag = false;
        for (auto &p : partas) {
            if (!(h >= p.first && h <= p.second)) {
                d = min(d, min(abs(h - p.first), abs(h - p.second)));
            } else {
                flag = true;
            }
        }
        if (!flag)
            if (d != inf) temp += d;
    }
    if (temp != 0) ans = min(ans, temp);
}

cin >> t >> n >> k;

while (k--) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    partas.push_back(p);
}

for (int i = 0; i < t; i++) {
    solve();
}

if (ans == inf) {
    cout << 0 << '\n';
} else {
    cout << ans << '\n';
}