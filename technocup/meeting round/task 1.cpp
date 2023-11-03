int n, k;
cin >> n >> k;

int a;
for (int i = 0; i < n; i++) {
    cin >> a;
    k -= a;
}

if (k <= 0)
    cout << 0 << '\n';
else
    cout << k << '\n';