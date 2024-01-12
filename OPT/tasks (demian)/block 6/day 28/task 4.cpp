string a, b, c;
cin >> a >> b >> c;

int n = (int)a.size();
vector<int> p(n);
iota(p.begin(), p.end(), 0);

int ans = 0;
do {
    int _a = 0, _b = 0, _c = 0;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        _a = _a * 10 + (a[p[i]] - '0');
        _b = _b * 10 + (b[p[i]] - '0');
        _c = _c * 10 + (c[p[i]] - '0');
        if (i == 0 && (_a == 0 || _b == 0 || _c == 0)) {
            flag = true;
            break;
        }
    }
    if (!flag && _a + _b == _c) ans++;
} while (next_permutation(p.begin(), p.end()));

cout << ans << "\n";