int n, k, a, b;
cin >> n >> k;

vector<pair<int, int>> v;

int ans = 0;
for (int i = 0; i < n; i++) {
    cin >> a >> b;
    ans += a;

    v.push_back({b, a / b});
    v.push_back({a % b, 1});
}

sort(v);
reverse(all(v));

int count;
for (auto &[a, b] : v) {
    count = min(b, k);
    k -= count;
    ans -= a * count;
}

cout << ans << '\n';