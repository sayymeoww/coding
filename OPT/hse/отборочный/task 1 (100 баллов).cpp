int n, m, k;
cin >> n >> m >> k;

int a = n * (m - 1), b = (n - 1) * m;

if (k == 1)
    cout << 0 << '\n';
else {
    int answer = a;
    if (k < m) answer += b;
    cout << answer << '\n';
}