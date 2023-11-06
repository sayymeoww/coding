int leader(int x, vector<int> &p) {
    if (p[x] == -1) return x;
    return p[x] = leader(p[x], p);
}

void unite(int x, int y, vector<int> &p, vector<int> &rank) {
    int a = leader(x, p);
    int b = leader(y, p);

    if (a != b) {
        if (rank[a] > rank[b]) {
            rank[a] += rank[b];
            p[b] = a;
        } else {
            rank[b] += rank[a];
            p[a] = b;
        }
    }
}

int n;
cin >> n;

vector<int> a(n);
for (int i = 0; i < n; i++) cin >> a[i];

vector<int> v(n);
for (int i = n - 1; i >= 0; i--) cin >> v[i];

vector<int> p(n, -1), rank(n), result(1, 0), states(n, 0);
for (int i = 0; i < n; i++) rank[i] = a[i];

int m = 0;
for (int i = 0; i < n; i++) {
    int ind = v[i] - 1;
    states[ind] = 1;

    if (ind - 1 >= 0 && states[ind - 1]) unite(ind - 1, ind, p, rank);
    if (ind + 1 < n && states[ind + 1]) unite(ind + 1, ind, p, rank);

    m = max(m, rank[leader(ind, p)]);
    result.push_back(m);
}

reverse(result.begin(), result.end());
for (int i = 1; i < (int)result.size(); i++) {
    cout << result[i] << '\n';
}