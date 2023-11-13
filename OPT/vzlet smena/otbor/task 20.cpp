const int maxn = 101;

int n;
set<int> g[maxn];
vector<bool> used(maxn);

void dfs(int v) {
    used[v] = true;
    for (auto &i : g[v])
        if (!used[i]) dfs(i);
}

int n, m;
cin >> n >> m;

int u, v;
for (int i = 0; i < m; i++) {
    cin >> u >> v;
    g[u].insert(v);
    g[v].insert(u);
}

int comp = 0;
for (int i = 1; i <= n; i++) {
    if (!used[i]) {
        dfs(i);
        comp++;
    }
}

if (comp == 1)
    cout << "YES" << '\n';
else
    cout << "NO" << '\n';