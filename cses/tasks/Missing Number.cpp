int n;
cin >> n;

int s = 0, a;
for (int i = 0; i < n - 1; i++) {
    cin >> a;
    s += a;
}

cout << n * (n + 1) / 2 - s << '\n';