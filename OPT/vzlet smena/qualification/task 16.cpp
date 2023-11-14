int n, k, s = 0;
cin >> n >> k;

vector<int> v(n);
for (int i = 0; i < n; i++) {
    cin >> v[i];
    s += v[i];
}

int l = 0, r = 1e7 + 1, m;
while (r > l + 1) {
    m = (l + r) / 2;
    int s = 0;
    for (auto &el : v) s += el / m;
    if (s < k)
        r = m;
    else
        l = m;
}

cout << l << '\n';