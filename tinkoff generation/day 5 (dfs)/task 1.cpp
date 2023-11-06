const int maxn = 1e5 + 1;

vector<int> g[maxn];
vector<int> used(maxn);

bool flag = false;
void dfs(int v) {
    used[v] = 1;
    for (auto &u : g[v]) {
        if (used[u] == 1) flag = true;
        if (used[u] == 0) dfs(u);
    }
    used[v] = 2;
}

int n, m;
cin >> n >> m;

int u, v;
while (m--) {
    cin >> u >> v;
    g[u].push_back(v);
}

for (int u = 1; u <= n; u++) {
    if (used[u] == 0) dfs(u);
    if (flag) {
        cout << 1 << '\n';
        return 0;
    }
}

cout << 0 << '\n';