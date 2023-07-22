int f(int n, int m) {
    int answer = 1;

    if (n >= m)
        return 0;

    for (int i = 1; i <= n; i++)
        answer *= (n % m);

    return answer % m;
}

int n, m, t = 3;
while (t--) {
    cin >> n >> m;
    cout << f(n, m) << '\n';
}