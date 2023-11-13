int n;
cin >> n;

vector<int> a(n);
for (int i = 0; i < n; i++) cin >> a[i];

int m;
cin >> m;

vector<int> b(m);
for (int i = 0; i < m; i++) cin >> b[i];

for (int i = 0; i < n; i++) {
    int cnt = 1;
    for (int j = 0; j <= i - 1; j++)
        if (a[j] == a[i]) cnt++;
    for (int j = 0; j < m; j++)
        if (a[i] == b[j]) cnt--;
    if (cnt <= 0) cout << a[i] << " ";
}
cout << '\n';