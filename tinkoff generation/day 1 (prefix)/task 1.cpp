int n, m, k;
cin >> n >> m >> k;

vector<int> v(100001);
for (int i = 0; i < n; i++) cin >> v[i];

vector<vector<int>> r(m, vector<int>(3, 0));
for (int i = 0; i < m; i++) {
    cin >> r[i][0] >> r[i][1] >> r[i][2];

    r[i][0]--;
    r[i][1]--;
}

vector<int> b(100001, 0);
for (int i = 0; i < k; i++) {
    int f, t;
    cin >> f >> t;

    f--;
    t--;

    b[f]++;
    b[t + 1]--;
}

int count = 0;
vector<int> p(100001, 0);
for (int i = 0; i < m; i++) {
    count += b[i];
    p[r[i][0]] += count * r[i][2];
    p[r[i][1] + 1] -= count * r[i][2];
}

count = 0;
for (int i = 0; i < n; i++) {
    count += p[i];
    cout << count + v[i] << " ";
}
cout << '\n';