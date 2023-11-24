int n, w;
cin >> n >> w;

bitset<6250000> b;
b[0] = 1;

vector<int> v(n);
for (int i = 0; i < n; i++) cin >> v[i];

for (int i = 0; i < n; i++) {
    b |= (b << v[i]);
}

if (b[w] == 0) {
    cout << "NO" << '\n';
    return 0;
}

set<pair<int, int>, greater<pair<int, int>>> s;
vector<int> ans;

for (int i = 0; i < n; i++) {
    s.insert({v[i], i});
}

for (int i = 1; i <= n; i++) {
    for (auto &j : s) {
        if (w - j.first >= 0 && b[w - j.first]) {
            ans.push_back(j.second + 1);
            w -= j.first;
            s.erase(j);
            break;
        }
    }
}

sort(ans);

cout << "YES" << '\n';
cout << ans.size() << '\n';
for (auto &el : ans) cout << el << " ";
cout << '\n';