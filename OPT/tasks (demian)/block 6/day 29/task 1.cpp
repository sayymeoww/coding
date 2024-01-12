int n, m, mx = 0, ind;
cin >> n >> m;

vector<int> v(m), u(n);
for (int i = 0; i < m; i++) cin >> v[i];

for (int i = 0; i < m; i++) {
    u[v[i] - 1]++;
    if (u[v[i] - 1] > mx) {
        mx = u[v[i] - 1];
        ind = i;
    }
}

cout << v[ind] << '\n';