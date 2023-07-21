int t;
cin >> t;

int n, a, b, c;
cin >> n >> a >> b >> c;

if (t == 2)
    cout << min({a, b, c}) << '\n';
else {
    int answer = a + b + c - 2 * n;
    cout << ((answer < 0) ? 0 : answer) << '\n';
}