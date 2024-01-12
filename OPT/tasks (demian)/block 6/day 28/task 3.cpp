int n, m, c;
cin >> n >> m >> c;

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cout << (i + j) % c + 1 << " ";
    }
    cout << '\n';
}