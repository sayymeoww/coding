int n, mx = -inf;
cin >> n;

vector<int> v(n), a(n), b(n);
for (int i = 0; i < n; i++) {
    cin >> v[i];
    mx = max(mx, v[i]);
}

for (int i = 1; i <= n; i++) {
    if (v[i] != 0) {
        if (v[i] < v[i - 1]) v[i - 1] = v[i];
    }
}

// for (int i = 0; i < n; i++) cout << v[i] << " ";
// cout << '\n';

int t;
for (int i = 0; i < n; i++) {
    if (v[i] == 0) {
        mx = max(mx, t);
        t = 0;
    } else {
        t += v[i];
    }
}
mx = max(mx, t);

cout << mx << '\n';