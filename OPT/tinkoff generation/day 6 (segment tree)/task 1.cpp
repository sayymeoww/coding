const int lg = 18, maxn = 1e5 + 1;
vector<int> a(maxn), deg(maxn);
vector<vector<pair<int, int>>> sparse(lg, vector<pair<int, int>>(maxn));

pair<int, int> get(int l, int r) {
    int k = deg[r - l + 1];
    pair<int, int> answer;
    answer.first = max(sparse[k][l].first, sparse[k][r - (1 << k) + 1].first);
    answer.second = (sparse[k][l].first > sparse[k][r - (1 << k) + 1].first
                         ? sparse[k][l].second
                         : sparse[k][r - (1 << k) + 1].second);
    return answer;
}

int n;
cin >> n;
for (int i = 1; i <= n; i++) cin >> a[i];
for (int i = 1; i <= n; ++i) {
    sparse[0][i].first = a[i];
    sparse[0][i].second = i;
}

for (int k = 0; k < lg - 1; ++k)
    for (int i = 1; i <= n; ++i) {
        int j = min(i + (1 << k), n);
        sparse[k + 1][i].first = max(sparse[k][i].first, sparse[k][j].first);
        sparse[k + 1][i].second = (sparse[k + 1][i].first == sparse[k][i].first
                                       ? sparse[k][i].second
                                       : sparse[k][j].second);
    }

deg[1] = 0;
for (int a = 2; a <= n; ++a) {
    deg[a] = deg[a - 1];
    if (!(a & (a - 1))) ++deg[a];
}

int k, l, r;
cin >> k;
while (k--) {
    cin >> l >> r;
    pair<int, int> ans = get(l, r);
    cout << ans.first << ' ' << ans.second << '\n';
}