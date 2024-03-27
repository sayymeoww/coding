const int maxn = 3e5 + 1;
int c[maxn];

int n, m;
cin >> n >> m;

for (int i = 0; i < n; i++) {
    cin >> c[i];
}

for (int i = 0; i < m; i++) {
    int l, r, k;
    cin >> l >> r >> k;

    l = l - 1;
    r = r - 2;
    int len = r - l + 2;

    vector<int> s;
    for (int j = l; j <= r; j++) {
        for (int x = 0; x < (j + 1 - l) * len + (j + 1 - l) * (j - l); x++) {
            s.push_back(c[j]);
        }
    }
    sort(s);
    cout << s[k - 1] << '\n';
}