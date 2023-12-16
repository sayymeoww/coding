int n;
cin >> n;
vector<int> a(n);
for (int i = 0; i < n; i++) {
    cin >> a[i];
}

vector<pair<int, int>> ans;

for (int i = 0; i < n; i++) {
    for (int j = 0; j + 1 < n; j++) {
        if (a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
            ans.push_back({j, j + 1});
        }
    }
}

cout << (int)ans.size() << '\n';
for (auto& el : ans) {
    cout << el.first + 1 << " " << el.second + 1 << '\n';
}