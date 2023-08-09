int n, p;
cin >> n >> p;

vector<int> z(n), a(n), b(n);
for (int i = 0; i < n; i++) {
    cin >> z[i] >> a[i] >> b[i];
}

int x = 1, cur;
while (true) {
    cur = 0;
    for (int i = 0; i < n; i++) {
        if (x <= z[i]) {
            cur += a[i] * x;
        } else {
            cur += a[i] * z[i] + b[i] * (x - z[i]);
        }
    }
    if (cur >= p) break;
    x++;
}

cout << x << '\n';