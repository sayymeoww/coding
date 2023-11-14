int n;
cin >> n;

vector<int> v(n);
for (int i = 0; i < n; i++) cin >> v[i];

int count = 0;
for (int i = 1; i <= n - 2; i++) {
    if (v[i] > v[i - 1] && v[i] > v[i + 1]) count++;
}

cout << count << '\n';