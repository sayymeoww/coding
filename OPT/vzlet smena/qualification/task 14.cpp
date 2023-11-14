int fast(int a, int n, int m) {
    if (n == 0) return 1;
    if (n % 2 == 1) return (a * fast(a, n - 1, m)) % m;
    int t = fast(a, n / 2, m);
    return (t * t) % m;
}

int n, m;
cin >> n >> m;
cout << fast(n, n, m) << '\n';
