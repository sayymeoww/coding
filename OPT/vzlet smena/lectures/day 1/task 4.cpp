int n, k;
cin >> n >> k;

set<int> check;

vector<pair<int, int>> a(n);
for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    check.insert(a[i].first);
    a[i].second = i;
}

if (check.size() < k) {
    cout << -1 << '\n';
    return 0;
}

sort(a);
reverse(all(a));

set<int> values;
vector<int> b;
vector<bool> used(n);
for (int i = 0; i < n; i++) {
    int t = a[i].first;
    if (values.count(t) == 0) {
        used[i] = true;
        values.insert(t);
        b.push_back(a[i].second + 1);
    }
    if (b.size() == k) break;
}

if (b.size() < k) {
    cout << -1 << '\n';
    return 0;
}

reverse(all(b));

for (auto &el : b) cout << el << " ";
for (int i = 0; i < n; i++)
    if (!used[i]) cout << a[i].second + 1 << " ";
cout << '\n';