int n, k, x;
list<pair<int, int>> seg;

cin >> n >> k;

for (int i = 0; i < n; i++) {
    if (!seg.empty() && i - seg.front().first >= k) {
        seg.pop_front();
    }
    cin >> x;

    while (!seg.empty() && seg.back().second > x) {
        seg.pop_back();
    }
    seg.push_back({i, x});

    if (i + 1 >= k) cout << seg.front().second << " ";
}
cout << '\n';